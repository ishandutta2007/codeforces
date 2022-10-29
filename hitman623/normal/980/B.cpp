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
int a[4][100];
void solve(){
    int n,k;
    cin>>n>>k;
    if(k==2*n-4){
        rep(i,1,n-1){
            a[1][i]=a[2][i]=1;
        }
    }
    else{
        if(k%2==0){
            rep(i,1,n-1){
                if(!k) break;
                a[1][i]=1;
                a[2][i]=1;
                k-=2;
            }
        }
        else{
            if(k<=n-2){
                a[1][n/2]=1;
                k--;
                int g=n/2-1;
                rep(i,0,k/2){
                    a[1][g]=a[1][n-1-g]=1;
                    g--;
                }
            }
            else{
                k-=n-2;
                rep(i,1,n-1){
                    a[1][i]=1;
                }
                if(k){
                    k-=2;
                    a[2][1]=1;
                    a[2][n-2]=1;
                    rep(i,0,k){
                        a[2][i+2]=1;
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,4){
        rep(j,0,n){
            if(a[i][j]) cout<<"#";
            else cout<<".";
        }
        cout<<endl;
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