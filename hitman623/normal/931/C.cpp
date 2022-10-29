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
int n,x[100005];
mi mp;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i];
        mp[x[i]]++;
    }
    sort(x,x+n);
    if(x[n-1]-x[0]<=1){
        cout<<n<<endl;
        rep(i,0,n){
            cout<<x[i]<<" ";
        }
        return;
    }
    int g=(x[0]+x[n-1])/2,cnt=mp[g];
    if(cnt-cnt%2>2*min(mp[x[0]],mp[x[n-1]])){
        cout<<n-cnt+cnt%2<<endl;
        rep(i,0,n-1){
            if(x[i]==x[i+1] and x[i]==g){
                x[i]-=1;
                x[i+1]+=1;
            }
            cout<<x[i]<<" ";
        }
        cout<<x[n-1]<<endl;        
    }
    else{
        int cur=min(mp[x[0]],mp[x[n-1]]);
        cout<<n-2*cur<<endl;
        rep(i,0,cur){
            x[i]+=1;
            x[n-i-1]-=1;
        }
        rep(i,0,n){
            cout<<x[i]<<" ";
        }
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