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
int n,a[200005],b[200005];
map<int,priority_queue<int,vi,greater<int>>> mp;
void solve(){
    priority_queue<pii,vii,greater<pii>>pq;
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        mp[a[i]].push(i);
        int cur=a[i];
        while(cur<=1e9){
            mp[cur];
            cur*=2;
        }
    }
    for(auto i:mp){
        while(sz(i.y)>1){
            int x=i.y.top();
            i.y.pop();
            int y=i.y.top();
            i.y.pop();
            b[x]=0;
            b[y]=2*i.x;
            mp[2*i.x].push(y);
        }
        if(sz(i.y)){
            int d=i.y.top();
            i.y.pop();
            b[d]=i.x;
        }
    }
    int cnt=0;
    rep(i,0,n){
        if(b[i]) cnt++;
    }
    cout<<cnt<<endl;
    rep(i,0,n){
        if(b[i]) cout<<b[i]<<" ";
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