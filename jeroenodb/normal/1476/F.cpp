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
struct MAX {
    int operator()(int a, int b) const {
        return max(a,b);
    }
};
struct MIN {
    int operator()(int a, int b) const {
        return min(a,b);
    }
};
template<class OP>
struct segtree {
    OP op;
    int ptwo, f;
    vi seg;
    // Weights are stored in nodes instead of edges
    // seg[node+ptwo] = weight of Edge to parent
    int& operator[](int a) {
        return seg[a+ptwo];
    }
    segtree(){}
    segtree(const segtree& o) {
        ptwo = o.ptwo;
        seg = o.seg;
        f = o.f;
    }
    segtree(int nn, int _f = -1) {
        ptwo=1;
        f = _f;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,f);
    }
    int query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        int res = f;
        while(l<=r) {
            if(l%2==1) res = op(res,seg[l++]);
            if(r%2==0) res = op(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    // int findmin(int m) {
    //     int l=0,r = ptwo-1,i =1;
    //     while(true) {
    //         if(l==r) {
    //             return (seg[i]==f?oo:l);
    //         }
    //         int mid = (l+r)/2;
    //         if(m <=mid and seg[i*2]<=f) {
    //             i=i*2;
    //             r=mid;
    //         } else {
    //             i=i*2+1;
    //             l=mid+1;
    //         }
    //     }
    //     assert(false);
    // }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = val;
        for(i/=2;i>=1;i/=2) {
            seg[i] = op(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>0;--i) {
            seg[i] = op(seg[i*2],seg[i*2+1]);
        }
    }
};
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi p(n); for(int& i: p) cin >> i;
        segtree<MAX> furthest(n);
        for(int i=0;i<n;++i) furthest.seg[i+furthest.ptwo] = i+p[i];
        furthest.build();
        segtree<MAX> pseg(furthest);
        for(int i=n-2;i>=0;--i) {
            furthest.update(i, furthest.query(i,min(n-1,i+p[i]) ) );
        }
        segtree<MIN> dp(n,oo);
        vi from(n);
        for(int i=1;i<n;++i) {
            int cur = -1;

            if(p[i]>=i) {
                cur = pseg.query(0,i-1);
                if(cur>i and cur<n) {
                    cur = furthest.query(i+1,min(n-1,cur));
                }
            } else {
                int l = dp.query(i-p[i]-1, n-1);
                if(l<i) {
                    from[i] = l;
                    cur = i-1;
                    int to = pseg.query(l+1,i-1);
                    if(to>=i+1 and i+1 < n) {
                        cur = max(cur,furthest.query(i+1,min(n-1,to)));
                    } else {
                        cur = max(cur,to);
                    }
                }
            }
            // int tmp = dp.query(0,i-1);
            // if(tmp==-1 and cur==-1) continue;
            // if(tmp>=cur) {
            //     int par = dp.findfirst(0,tmp);
            //     assert(par!=oo);
            //     from[i] = from[par];
            //     dp.update(i,tmp);
            // } else {
            cur = min(cur,n-1);
            if(cur>=0)
                dp.update(cur,min(dp[cur],i));
            // }

            if(dp[n-1]<oo) 
                break;
        }
        bool found = false;
        int id = -1;
        if(dp[n-1]<oo) {
            found = true;
            id = dp[n-1];
        }
        if(found) {
            cout << "YES\n";
            string s(n,'R');
            while(id!=0) {
                s[id] = 'L';
                id = from[id];
            }
            cout << s << endl;
        } else {
            cout << "NO\n";
        }
    
    }
}