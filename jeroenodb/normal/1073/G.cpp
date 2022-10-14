#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct segtree {
    int ptwo;
    vector<int> seg;
    segtree(){}
    int& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,0);
    }
    auto query(int l, int r) {
        if(l>r) return oo;
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        int res = oo;
        while(l and l<=r) {
            if(l%2==1) res = min(res,seg[l++]);
            if(r%2==0) res = min(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = val;
        for(i/=2;i>=1;i/=2) {
            seg[i] = min(seg[2*i],seg[2*i+1]);
        }
    }
};
vector<int> suffixArray(string& s, int symbols = 28) {

    s.push_back('a'-1);
    int n = s.length();
    vector<int> oldlabel(n);
    for (int i = 0; i < n-1; ++i) {
    oldlabel[i] = s[i] - 'a' + 1;
    }

    vector<int> sufarr(n);
    iota(all(sufarr),0);
    sort(all(sufarr), [&](int a, int b) {return oldlabel[a] < oldlabel[b];});
    int maxk = 0;
    while ((1 << maxk) < n) ++maxk;
    
    // output of radix sort
    int mxCnt = max(symbols+1,n);
    vector<int> output(n),count(mxCnt);
    for (int k = 0; k < maxk; ++k) {
        for(int& i: sufarr) {
            i-=1<<k;
            while(i<0) i+=n;
        }
        //radix sort
        fill(count.begin(),count.end(),0);
        for(int i=0;i<n;++i) {
            count[oldlabel[i]]++;
        }
        for(int i=1;i<mxCnt;++i) {
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;--i) {
            output[--count[oldlabel[sufarr[i]]]] = sufarr[i];
        }
        swap(sufarr,output);
        output[sufarr[0]] = 0;
        int l = 0;
        for (int i = 1; i < n; ++i) {
                int io = sufarr[i]+(1<<k);
                while(io>=n) io-=n;
                int jo = sufarr[i-1]+(1<<k);
                while(jo>=n) jo-=n;
            if (pair<int,int>{oldlabel[sufarr[i]],oldlabel[io]}  > pair<int,int>{oldlabel[sufarr[i - 1]], oldlabel[jo]} ) 
                    l++;
            output[sufarr[i]] = l;
        }
        swap(output,oldlabel);
     if(l==n-1) break;
 }
 #ifdef LOCAL
         for(int i=0;i<n;++i) {
            cout << s.substr(sufarr[i]) << endl;
        } cout << endl;
#endif
    return sufarr;
}
vector<int> kasai(string& s, vector<int>& sa, vi& rank) {
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0) {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}
struct myst {
    struct el {
        int lcp=0,cnt=0;
        ll sum=0;
    };
    vector<el> st = {{}};
    void minimize(int k) {
        if(k==0) {
            while(st.size()>1) st.pop_back();
            return;
        }
        el nw;
        nw.lcp=k;
        while(st.back().lcp>=k) {
            auto c = st.back().cnt;
            st.pop_back();
            nw.cnt+=c;
            nw.sum+=ll(c)*k;
        }
        nw.sum+=st.back().sum;
        st.push_back(nw);
    }
    ll get() {
        return st.back().sum;
    }
    void add(int len) {
        st.push_back({len, 1,len+st.back().sum});
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    string s; cin >> s;
    auto sa = suffixArray(s);
    vector<int> rank(n+1,0);
    auto lcp = kasai(s,sa,rank);
    segtree seg(n+1);
    for(int i=0;i<=n;++i) {
        seg.update(i,lcp[i]);
    }
    while(q--) {
        int k,l; cin >> k >> l;
        vi a(k),b(l);
        for(auto& i : a) {
            cin >> i, i = rank[i-1];
        }
        for(auto& i : b) {
            cin >> i, i = rank[i-1];
        }
        sort(all(a)),sort(all(b));
        // now do the annoying part
        myst as,bs;
        auto it = a.begin(), it2 = b.begin();
        auto e = a.end(), e2 = b.end();
        ll ans = 0;
        int last=0;
        while(it!=e or it2!=e2) {
            if(it!=e and (it2==e2 or *it<*it2)) {
                auto have = seg.query(last,*it - 1);
                as.minimize(have);
                bs.minimize(have);
                // have to get range minimum! :(
                ans+=bs.get();
                as.add(n-sa[*it]);
                last=*it;
                ++it;
            } else {
                auto have = seg.query(last,*it2 - 1);
                as.minimize(have);
                bs.minimize(have);
                ans+=as.get();
                bs.add(n-sa[*it2]);
                last=*it2;
                ++it2;
            }
        }
        cout << ans << '\n';
    }
}