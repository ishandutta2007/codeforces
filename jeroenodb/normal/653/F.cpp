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
vector<int> suffixArray(const vi& s) {
    int n = s.size();
    vector<int> oldlabel(n);
    oldlabel=s;

    vector<int> sufarr(n);
    iota(all(sufarr),0);
    sort(all(sufarr), [&](int a, int b) {return oldlabel[a] < oldlabel[b];});
    {
    int rnk=-1,prev=-1;
    for(auto i : sufarr) { // coordinate compression
        if(s[i]!=prev) ++rnk;
        oldlabel[i]=rnk;
        prev=s[i];
    }
    }
    int maxk = 0;
    while ((1 << maxk) < n) ++maxk;
    
    // output of radix sort
    int mxCnt = n+3;
    vector<int> output(n),count(mxCnt);
    for (int k = 0; k < maxk; ++k) {
        for(int& i: sufarr) {
            i-=1<<k;
            while(i<0) i+=n;
        }
        // radix sort
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
        // for(int i=0;i<n;++i) {
        //     cout << s.substr(sufarr[i]) << endl;
        // } cout << endl;
     if(l==n-1) break;
 }
    return sufarr;
}
vector<int> kasai(const vi& s, vector<int>& sa) {
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0) {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}
struct tree {
    vvi g;
    map<vi,int> mp; // map of children equivalence classes -> own equivalence class
    vi equiv;
    void gets(int at, vi& str) {
        for(auto to : g[at]) {
            str.push_back(equiv[to]);
        }
    }
    int get(vi& v) {
        auto it = mp.find(v);
        if(it!=mp.end()) return it->second;
        mp[v]=mp.size();
        return mp.size()-1;
    }
    tree(int n) {
        g.resize(n+1);
    }
    void add(int i, int par) {
        while((int)g.size()<=max(i,par)) g.push_back({});
        g[par].push_back(i);
    };
    void init() {
        equiv.resize(g.size(),-1);
    }
    void dfs(int at) {
        vi str; str.reserve(g[at].size());
        for(auto to : g[at]) {
            dfs(to);
            str.push_back(equiv[to]);
        }
        equiv[at] = get(str);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    vi mate(n+1,-1), st;
    for(int i=0;i<n;++i) {
        if(s[i]=='(') st.push_back(i);
        else if(!st.empty()) {
            mate[i] = st.back();
            mate[st.back()] = i;
            st.pop_back();
        }
    }
    st.clear();
    tree tr(n);
    for(int i=0;;) {
        while(i<n and mate[i]==-1)
            ++i;
        if(i==n) break;
        int j=i;
        while(mate[j]!=-1) 
            ++j;
        // [i,j) is good bracket sequence
        st = {(int)tr.g.size()};
        tr.add(st[0],n);
        for(int k=i;k<j;++k) {
            assert(mate[k]!=-1);
            if(s[k]=='(') st.push_back(mate[k]);
            else {
                st.pop_back();
                tr.add(k,st.back());
            }
        }
        i=j;
    }
    tr.init();
    tr.dfs(n);
    vi str; 
    ll ans=0;
    int num=1e7;
    for(int i=0;i<(int)tr.g.size();++i) if(i!=n) {
        tr.gets(i,str);
        ll len = tr.g[i].size();
        if(len==0) continue;
        ans+=len*(len+1)/2;
        str.push_back(num++);
    }
    auto sa = suffixArray(str);
    auto lcp = kasai(str,sa);
    ans-=accumulate(all(lcp),0LL);
    cout << ans << '\n';
}