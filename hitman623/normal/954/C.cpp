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
int n,a[200005];
set<int> s;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n-1){
        if(abs(a[i]-a[i+1])!=1) s.insert(abs(a[i]-a[i+1]));
    }
    if(sz(s)>1) {cout<<"NO";return;}
    if(sz(s)==0){
        cout<<"YES\n";
        cout<<1<<" "<<1000000000<<endl;
        return;
    }
    int r=*s.begin();
    if(r==0) {cout<<"NO";return;}
    rep(i,0,n-1){
        if(a[i]%r==0){
            if(a[i+1]==a[i]+1) {cout<<"NO";return;} 
        }
        if(a[i]%r==1){
            if(a[i+1]==a[i]-1) {cout<<"NO";return;}
        }
    }
    cout<<"YES\n";
    cout<<1000000000<<" "<<r<<endl;
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