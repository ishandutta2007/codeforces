#ifndef LOCAL
#pragma GCC optimize("O3","unroll-loops")
#endif
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
unsigned a[mxN],b[mxN],c[mxN],d[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    fill_n(b,mxN,oo);
    fill_n(a,mxN,oo);
    while(q--) {
        int t,l,r; cin >> t >> l >> r;
        --l,--r;
        if(t==1) {
            int k; cin >> k;
            if(k>0) {
                fill(c+l,c+r,~0U);
                #pragma GCC ivdep
                for(;l!=r;++l) {
                    a[l]=min(a[l],(unsigned)k);
                }
            } else {
                k=-k;
                
                fill(d+l,d+r,~0U);
                #pragma GCC ivdep
                for(;l!=r;++l) {
                    b[l]=min(b[l],(unsigned)k);
                }
            }
        } else {
            ll ans=0;
            for(;l!=r;++l) {
                ans+=(a[l]+b[l])&c[l]&d[l];
            }
            cout << ans << '\n';
        }
    }

}