#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 100010;
ll N,R,m=-100000000;
ll T[MAXN],x[MAXN],y[MAXN],dp[MAXN],tkn[MAXN];
int main(){
    cin >> R >> N;
    T[0]=0; x[0]=1; y[0]=1;
    for(int i = 1; i <= N; i++){
        cin >> T[i]>>x[i]>>y[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = i-1; j >= 0 ; j--){
            if(T[i]-T[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]) && (j == 0 || dp[j]))dp[i]=max(dp[j]+1,dp[i]);
            if(T[i]-T[j]>2*R){
                if(tkn[j])break;
                tkn[j]=1;
                m = max(dp[j],m);
            }
        }
        dp[i]=max(dp[i],m+1);
        //cout << i << " " <<dp[i]<<" m "<<m <<endl;
    }
    ll ans = 0;
    for(int i = 0; i<=N; i++)ans = max(ans,dp[i]);

    cout << ans;
    return 0;
}