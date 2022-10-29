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
int n;
vector<pair<pii,int>> v;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v.pb({{x,-y},i+1});
    }
    sort(all(v));
    int l=-v[0].x.y,cur=0;
    rep(i,1,n){
        if(-v[i].x.y<=l){
            cout<<v[i].y<<" "<<v[cur].y<<endl;
            return;
        }
        else{
            l=-v[i].x.y;
            cur=i;
        }
    }
    cout<<-1<<" "<<-1<<endl;
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