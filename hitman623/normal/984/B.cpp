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
int n,m,f=1;
vi vx={-1,0,1},vy={-1,0,1};
string s[102];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>s[i];
    }
    rep(i,0,n){
        rep(j,0,m){
            int cnt=0;
            for(auto dx:vx){
                for(auto dy:vy){
                    if(i+dx>=0 and i+dx<n and j+dy>=0 and j+dy<m and s[i+dx][j+dy]=='*'){
                        cnt++;
                    }
                }
            }
            if((isdigit(s[i][j]) and cnt!=s[i][j]-'0') || (s[i][j]=='.' and cnt)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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