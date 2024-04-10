#include <bits/stdc++.h>

#define int         long long
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
int a[14];
void solve(){
    rep(i,0,14){
        cin>>a[i];
    }
    int ans=0;
    rep(i,0,14){
        if(a[i]){
            int cnt=0;
            int b[14];
            int h=a[i]/14,g=a[i]%14;
            rep(j,0,14){
                b[j]=a[j]+h;
            }
            b[i]=h;
            rep(j,1,g+1){
                b[(j+i)%14]++;
            }
            rep(j,0,14){
                if(b[j]%2==0){
                    cnt+=b[j];
                }
            }
            ans=max(ans,cnt);
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