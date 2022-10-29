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
int n,k,a[200005],cur,cnt;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    if(k==n){
        cur=1e9;
    }
    else{
        cur=a[k]-1;
    }
    rep(i,0,n){
        if(a[i]<=cur) cnt++;
    }
    if(cnt==k and cur>=1){
        cout<<cur<<endl;
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