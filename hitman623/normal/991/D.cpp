#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[1001][4];
string s[2];
void solve(){
    cin>>s[0]>>s[1];
    n=sz(s[0]);
    rep(i,0,n){
        rep(j,0,4){
            if(!(j&1) and s[0][i]!='0'){
                dp[i][j]=-hell;
                continue;
            }
            if(!(j&2) and s[1][i]!='0'){
                dp[i][j]=-hell;
                continue;
            }
            if(!i) continue;
            if(j==0){
                if(s[0][i-1]=='0' and s[1][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][2]+1);
                }
                else if(s[1][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][3]+1);    
                }
                if(s[1][i-1]=='0' and s[0][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][1]+1);
                }
                else if(s[0][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][3]+1);    
                }
                dp[i][j]=max({dp[i][j],dp[i-1][0],dp[i-1][3]});
            }
            else if(j==1){
                if(s[0][i-1]=='0' and s[1][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][3]+1);
                }
                dp[i][j]=max({dp[i][j],dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            }
            else if(j==2){
                if(s[0][i-1]=='0' and s[1][i-1]=='0'){
                    dp[i][j]=max(dp[i][j],dp[i-1][3]+1);
                }
                dp[i][j]=max({dp[i][j],dp[i-1][0],dp[i-1][1],dp[i-1][2]});     
            }
            else{
                dp[i][j]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
            }
        }
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]})<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}