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
int n,a,b,ans=0;
void solve(){
    cin>>n>>a>>b;
    cin>>s;
    int f=0,g=(a>b);
    rep(i,0,n){
        if(s[i]=='.'){
            if(f){
                if(g){
                    if(b){
                        ans++;
                        b--;
                    }
                }    
                else{
                    if(a){
                        ans++;
                        a--;
                    }
                }     
                f=0;
            }
            else{
                if(g){
                    if(a){
                        ans++;
                        a--;                        
                    }
                }
                else{
                    if(b){
                        ans++;
                        b--;
                    }
                }
                f=1;
            }
        }
        else{
            f=0;
            g=a>b;
        }
    }
    cout<<ans<<endl;
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