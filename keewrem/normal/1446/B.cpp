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

int N,M; string a,b;
int dp[5001][5001];
int ls[30];
int main(){
    cin >> N >> M >> a >> b;
    for(auto &x: a)x-='a';
    for(auto &x: b)x-='a';
    int ans = 0,k;
    for(int j = 0; j < 30; j++)ls[j]=-1;
    for(int i = 0; i < N; i++){
        ls[a[i]] = i;
        for(int j = 0; j < M; j++){
            if(j >0)dp[i][j] = max(dp[i][j],dp[i][j-1]-1);
            if(i > 0)dp[i][j] = max(dp[i-1][j]-1,dp[i][j]);
            if(ls[b[j]]>=0){
                k = 2;
                k+=ls[b[j]]-i;
                if(j > 0 && ls[b[j]]>0){
                    dp[i][j] = max(dp[i][j],dp[ls[b[j]]-1][j-1]+k);
                }
                dp[i][j] = max(dp[i][j],k);
            }
            ans = max(ans,dp[i][j]);
        //    cout << i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }

    }
    cout << ans <<"\n";
    return 0;
}