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
int query(int l, int r) {
    // [l,r) queries
    cout << "? " << l+1 << ' ' << r << endl;
    cin >> l;
    return l;
}
struct segt {
    segt* l = NULL, *r=NULL;
    int lo,hi;
    int zeros=-1;
    segt(int a, int b) {
        lo=a,hi=b;
        if(b-a==1) return;
        int mid = (lo+hi)/2;
        l = new segt(a,mid);
        r = new segt(mid,b);
    }
    void update() {
        zeros = hi-lo- query(lo,hi);
    }
    int kth(int k) { // adds one everywhere

        if(hi-lo==1) {
            zeros--;
            return 0;    
        }
        int len2 = (hi-lo)/2;
        if(l->zeros==-1) {
            l->update();
            r->zeros = zeros-l->zeros;
        }
        zeros--;
        if(l->zeros>=k) {
            return l->kth(k);
        } else return r->kth(k-l->zeros)+len2;
    }
};
int main() {
    int n,t; cin >> n >> t;
    segt rt(0,n);
    int k; cin >> k;
    rt.update();
    for(int i=0;i<t;++i) {
        
        int res = rt.kth(k);
        cout << "! " << res+1 << endl;
        if(i!=t-1) cin >> k;
    }
}