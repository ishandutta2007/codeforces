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
int n,ans=0;
string s,final;
void solve(){
    cin>>n>>s;
    rep(i,0,n){
        rep(j,0,n){
            string p;
            p+=s[i];
            p+=s[j];
            int cnt=0;
            rep(k,0,n-1){
                if(s[k]==p[0] and s[k+1]==p[1]) cnt++;
            }
            if(ans<cnt){
                ans=cnt;
                final=p;
            }
        }
    }
    cout<<final;
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