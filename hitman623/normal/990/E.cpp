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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,k,s[2000006],a[2000006];
ll res=hell;
int c[2000006];
void solve(){
    cin>>n>>m>>k;
    rep(i,0,m){
        int g;
        cin>>g;
        s[g]=1;
    }
    if(s[0]){
        cout<<-1<<endl;
        return;
    }
    rep(i,1,k+1){
        cin>>a[i];
    }
    rep(i,0,n+k+1){
        if(s[i]==0) c[i]=i;
        else c[i]=c[i-1];
    }
    rep(l,1,k+1){
        int cur=0,ans=0,f=1;
        while(cur<n){
            if(c[cur+l]==cur){
                f=0;
                break;
            }
            cur=c[cur+l];
            ans++;
        }
        if(f)
        res=min(res,1LL*a[l]*ans);
    }
    if(res!=hell){
        cout<<res<<endl;
    }
    else{
        cout<<-1<<endl;
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