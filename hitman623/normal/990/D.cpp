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
int n,a,b,m[1001][1001];
void solve(){
    cin>>n>>a>>b;
    if(a>1 and b>1){
        cout<<"NO"<<endl;
        return;
    }
    if(a==1 and b==1){
        if(n==1){
            cout<<"YES"<<endl;
            cout<<0;
            return;
        }
        if(n<=3){
            cout<<"NO"<<endl;
            return;
        }
        rep(i,1,n){
            m[i][i+1]=1;
            m[i+1][i]=1;
        }
        cout<<"YES"<<endl;
        rep(i,1,n+1){
            rep(j,1,n+1){
                cout<<m[i][j];
            }
            cout<<endl;
        }
        return;
    }
    if(a==1){
        rep(i,1,b){
            rep(j,1,n+1){
                if(i==j) continue;
                m[i][j]=1;
                m[j][i]=1;
            }
        }
        cout<<"YES"<<endl;
        rep(i,1,n+1){
            rep(j,1,n+1){
                cout<<m[i][j];
            }
            cout<<endl;
        }
        return;
    }
    if(b==1){
        rep(i,a,n+1){
            rep(j,a,n+1){
                if(i==j) continue;
                m[i][j]=1;
                m[j][i]=1;
            }
        }
        cout<<"YES"<<endl;
        rep(i,1,n+1){
            rep(j,1,n+1){
                cout<<m[i][j];
            }
            cout<<endl;
        }
        return;
    }
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