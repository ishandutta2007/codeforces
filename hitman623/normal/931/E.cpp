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
string s;
int dp[26][5005][26],f[26];
void solve(){
    cin>>s;
    int n=sz(s);
    rep(i,0,n){
        f[s[i]-'a']++;
    }
    rep(i,0,n){
        rep(j,0,n){
            dp[s[0]-'a'][j][s[j]-'a']++;
        }
        string temp;
        rep(j,1,n){
            temp+=s[j];
        }
        temp+=s[0];
        s=temp;
    }
    double p=0;
    rep(i,0,26){
        double h=0;
        rep(j,0,n){
            int cnt=0,cur=0;
            rep(k,0,26){
                if(dp[i][j][k]==1) cnt++;
                cur+=dp[i][j][k]; 
            }
            h=max(h,1.0*cnt/cur);
        }
        p+=h*f[i];
    }
    cout<<fixed<<setprecision(10)<<p/n<<endl;
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