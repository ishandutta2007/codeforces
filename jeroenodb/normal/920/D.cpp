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
const int mxN = 5000+1, oo = 1e9;
int main() {
    int n,k,v; cin >> n >> k >> v;
    vi a(n); for(auto& i : a) cin >> i;
    vector<bitset<mxN>> dp;
    dp.push_back({});
    dp[0][0]=true;
    for(int i : a) {
        auto ndp = dp.back();
        i%=k;
        ndp|=ndp<<i|ndp>>(k-i);
        dp.push_back(ndp);
    }
    // reconstruct set
    vector<bool> use(n);
    int vmd = v%k;
    int lu=-1, lnu=-1;
    for(int i=n-1;i>=0;--i) {
        int amd = a[i]%k;
        int nw = (vmd-amd+k)%k;
        if(dp[i][nw]) {
            use[i]=true;
            vmd = nw;
            lu=i;
        } else lnu=i;
    }
    vector<array<int,3>> ops;
    for(int i=lu+1;i<n;++i) if(use[i]) {
        ops.push_back({oo,i,lu});
        a[lu]+=a[i];
        a[i]=0;
    }
    if(lu==-1) lu=(lnu==0);
    for(int i=lnu+1;i<n;++i) if(!use[i]) {
        ops.push_back({oo,i,lnu});
        a[lnu]+=a[i];
        a[i]=0;
    }
    if(lnu==-1) lnu=(lu==0);
    if(a[lu]>v) {
        int dif = (a[lu]-v)/k;
        a[lu]-=dif*k;
        if(dif!=0) ops.push_back({dif,lu,lnu});
    } else if(a[lu]<v) {
        int dif = min(v-a[lu], a[lnu])/k;
        a[lu]+=dif*k;
        if(dif!=0) ops.push_back({dif,lnu,lu});
    }
    if(a[lu]==v) {
        cout << "YES\n";
        for(auto b : ops) {
            b[1]++,b[2]++;
            cout << b << '\n';
        }
    } else cout << "NO\n";

}