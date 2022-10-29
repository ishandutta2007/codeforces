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
int n,k,a[100005],p[256],v[256];
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,256){
        p[i]=i;
    }
    rep(i,0,n){
        int cur=-1,ans=-1;
        for(int j=a[i];j>=0 and a[i]-j+1<=k;j--){
            if(v[j]){
                cur=j;
                break;
            }
        }
        if(cur!=-1){
            if(a[i]-p[cur]+1<=k){
                rep(j,cur,a[i]+1){
                    p[j]=p[cur];
                    v[j]=1;
                }
                ans=p[cur];
            }
            else{
                rep(j,cur+1,a[i]+1){
                    p[j]=cur+1;
                    v[j]=1;
                }
                ans=cur+1;
            }
        }
        else{
            ans=max(0,a[i]-k+1);
            rep(j,ans,a[i]+1){
                p[j]=ans;
                v[j]=1;
            }
        }
        cout<<ans<<" ";
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