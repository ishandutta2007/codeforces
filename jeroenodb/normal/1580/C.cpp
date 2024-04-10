#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,mmx,popcnt,fma")
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
const int mxN = 2e5+1, oo = 1e9;
const int K = 330; // hehe
int prefsmall[K][K], prefbig[mxN];
int start[mxN],m,pp[K];
pi types[mxN];
int ans=0,t=-1;
void update(int k,int sgn) {
    int i = start[k];
    auto [x,y] = types[k];
    int len = x+y;
    if(sgn==-1 and (t-i)%len>=x) --ans;
    if(len<K) {
        prefsmall[len][i%len]-=sgn;
        prefsmall[len][(i+x)%len]+=sgn;
    } else {
        for(;i<m;i+=len) {
            prefbig[i]-=sgn;
            if(i+x<m) prefbig[i+x]+=sgn;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> m;
    for(int i=0;i<n;++i) {
        auto& [x,y] = types[i];
        cin >> x >> y;
    }
    for(t=0;t<m;++t) {
        int op,k; cin >> op >> k,--k;
        // update ans with big difference array
        ans+=prefbig[t];
        // update ans with small difference arrays
        for(int j=1;j<K;++j) {
            ans+=prefsmall[j][pp[j]++];
            if(pp[j]==j) pp[j]=0;
        }
        if(op==1) {
            start[k]=t;
            update(k,1);
        } else update(k,-1);
        cout << ans << '\n';
    }
}