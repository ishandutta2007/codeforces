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
int n,r,a[1<<20],s;
void solve(){
    cin>>n>>r;
    int m=(1<<n);
    rep(i,0,m){
        cin>>a[i];
        s+=a[i];
    }
    cout<<1.0l*s/m<<endl;
    rep(i,0,r){
        int x,y;
        cin>>x>>y;
        s+=y-a[x];
        a[x]=y;
        cout<<1.0l*s/m<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    cout<<fixed<<setprecision(10);
    while(t--){
        solve();
    }
    return 0;
}