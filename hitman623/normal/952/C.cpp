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
int n,a[11],b[11];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        rep(j,0,n-i-1){
            if(abs(a[j]-a[j+1])>=2) {cout<<"NO";return;}
        }
        int in=0;
        rep(j,0,n-i){
            if(a[in]<a[j]) in=j;
        }
        int cur=a[in];
        rep(j,in,n-1){
            a[j]=a[j+1];
        }
        a[n-1]=cur;
    }
    rep(i,0,n-1){
        if(abs(a[i]-a[i+1])>=2) {cout<<"NO";return;}
    }
    cout<<"YES"<<endl;
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