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
int n,x1,x2;
pii c[300005];
void solve(){
    cin>>n>>x1>>x2;
    rep(i,0,n){
        int g;
        cin>>g;
        c[i]={g,i+1};
    }
    sort(c,c+n);
    rep(i,0,n){
        int k1=(x1+c[i].x-1)/c[i].x;
        if(i+k1>=n) continue;
        int k2=(x2+c[i+k1].x-1)/c[i+k1].x;
        if(i+k1+k2>n) continue;
        cout<<"Yes"<<endl;
        cout<<k1<<" "<<k2<<endl;
        rep(j,i,i+k1){
            cout<<c[j].y<<" ";
        }
        cout<<endl;
        rep(j,i+k1,i+k1+k2){
            cout<<c[j].y<<" ";
        }
        return;
    }
    swap(x1,x2);
    rep(i,0,n){
        int k1=(x1+c[i].x-1)/c[i].x;
        if(i+k1>=n) continue;
        int k2=(x2+c[i+k1].x-1)/c[i+k1].x;
        if(i+k1+k2>n) continue;
        cout<<"Yes"<<endl;
        cout<<k2<<" "<<k1<<endl;
        rep(j,i+k1,i+k1+k2){
            cout<<c[j].y<<" ";
        }
        cout<<endl;
        rep(j,i,i+k1){
            cout<<c[j].y<<" ";
        }
        return;
    }
    cout<<"No"<<endl;
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