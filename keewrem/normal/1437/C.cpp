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

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        sort(v.begin(),v.end());
        int dp[N][3*N];
        for(int i=0; i < N; i++)for(int j = 0; j < 3*N; j++)dp[i][j]=1345675;
        for(int i = 1; i < 3*N; i++)dp[0][i]=abs(v[0]-i);
        for(int i = 1; i < N; i++){
            for(int j = i+1; j < 3*N; j++){
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j],dp[i-1][k]);
                }
                dp[i][j]+=abs(v[i]-j);
            }
        }
        int ans = 34512345;
        for(int i = 0; i < 3*N; i++)ans = min(ans,dp[N-1][i]);
        cout << ans << "\n";
    }
    return 0;
}