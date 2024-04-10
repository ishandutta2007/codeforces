#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 1e5+10;
int A[N],B[N], dp[N];
vector<pii> vec;
int main(){
    int t=1,n;
    // sd(t);
    while(t--){
        sd(n);  
        rep(i,0,n){
            sd(A[i]),sd(B[i]);
            vec.eb(mp(A[i],B[i]));
        }
        sort(all(vec));
        dp[0] = 0;
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            int x = vec[i-1].F, y = vec[i-1].S;
            pii p = mp(x - y - 1, 1000000000);
            int ind = upper_bound(all(vec),p)-vec.begin();
            dp[i] = dp[ind]+1;
            ans = max(ans,dp[i]);
        }
        pd(n-ans);
    }
}