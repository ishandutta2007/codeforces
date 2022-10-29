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
int n,k,a[101][101];
string s[101];
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>s[i];
    }
    rep(i,0,n){
        rep(j,0,n-k+1){
            int cur=0;
            rep(l,j,j+k){
                if(s[i][l]=='.') cur++;
            }
            if(cur==k){
                rep(l,j,j+k){
                    a[i][l]++;
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n-k+1){
            int cur=0;
            rep(l,j,j+k){
                if(s[l][i]=='.') cur++;
            }
            if(cur==k){
                rep(l,j,j+k){
                    a[l][i]++;
                }
            }
        }
    }
    int ans=0;
    pii pos={1,1};
    rep(i,0,n){
        rep(j,0,n){
            if(a[i][j]>ans){
                ans=a[i][j];
                pos={i+1,j+1};
            }
        }
    }
    cout<<pos.x<<" "<<pos.y<<endl;
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