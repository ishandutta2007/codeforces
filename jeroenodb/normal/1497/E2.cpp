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
const int store=1e7 + 11;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;i++) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
int strip(int a) {
    int tmp=0,res=1;
    // while(a%2==0) {
    //     a/=2;
    //     tmp++;
    // }
    // if(tmp%2==1) res=2;
    while(a!=1) {
        int f = factor[a];
        tmp=0;
        do {
            tmp++;
            a/=f;
        } while(factor[a]==f);
        if(tmp%2==1) res*=f;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vi a(n); for(auto& i : a) cin >> i,i=strip(i);
        {
            // coord compression
            vi order(n); iota(all(order),0);
            sort(all(order),[&](int c,int d) {return a[c]<a[d];});
            int last=-1,r=-1;
            for(auto i : order) {
                if(a[i]!=last) {
                    last=a[i],r++;
                }
                a[i]=r;
            }
        }
        vi dp[21];
        for(int i=0;i<=k;++i) dp[i] = vi(n+1,oo);
        dp[0][0]=0;
        vi cnt(n),prv(n+1);
        vi cand[21];
        for(int rep=0;rep<=k;++rep) {
            fill(all(cnt),0);
            int bad=0;
            for(int i=0,j=0;i<n;++i) {
                if(cnt[a[i]]++) bad++;
                while(bad>rep) {
                    if(--cnt[a[j++]]) bad--;
                }
                prv[i+1]=j;
            }
            cand[rep]=prv;
        }
        for(int j=0;j<=k;++j) {
            for(int i=1;i<=n;++i) {
                for(int rep=0;rep<=j;++rep)
                    dp[j][i]=min(dp[j][i],dp[j-rep][cand[rep][i]]+1);
            }
        }
        int ans = oo;
        for(int i=0;i<=k;++i) ans = min(ans,dp[i][n]);
        cout << ans << '\n';
    }
}