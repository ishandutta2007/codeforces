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
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp1[5005][5005],dp2[5005][5005];
char s[5005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>s[i];
    }
    dp1[0][0]=dp2[0][0]=1;
    rep(i,1,n){
        rep(j,0,n){
            if(s[i]=='f'){
                if(s[i-1]=='f') dp1[i][j]=(j?dp1[i-1][j-1]:0);
                else dp1[i][j]=dp2[i-1][j];
            }
            else{
                if(s[i-1]=='f') dp1[i][j]=(j?dp1[i-1][j-1]:0);
                else dp1[i][j]=dp2[i-1][j];
            }
        }
        for(int j=n-1;j>=0;j--){
            dp2[i][j]=(dp1[i][j]+dp2[i][j+1])%hell;
        }
    }
    cout<<dp2[n-1][0]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}