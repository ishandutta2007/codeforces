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
const int N = 5e2+10;
int c[N],dp[N][N];
int main(){
    int t=1,n;
    // sd(t);
    while(t--){
        sd(n);  
        rep(i,1,n+1) sd(c[i]);
        for(int i = n;i>=1;i--){
            dp[i][i] = 1;
            rep(j,i+1,n+1){
                dp[i][j] = 1+dp[i+1][j];
                if(i < n && c[i] == c[i+1]) dp[i][j] = min(dp[i][j],1+dp[i+2][j]);
                for(int k = i+2;k<=j;k++){
                    if(c[i]==c[k]){
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k+1][j]);
                    }
                }
            }
        }
        pd(dp[1][n]);
    }
}