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
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s;
vii v;
void solve(){
    cin>>s;
    int n=sz(s),ans=0,cur=1;
    rep(i,1,n){
        if(s[i]==s[i-1]) cur++;
        else{
            v.pb({cur,i-1});
            cur=1;
        }
    }
    if(cur) v.pb({cur,n-1});
    while(1){
        if(sz(v)<=1) break;
        v[0].x--;
        v.back().x--;
        rep(i,1,sz(v)-1){
            v[i].x-=2;
        }
        vii temp;
        rep(i,0,sz(v)){
            if(v[i].x<=0) continue;
            if(sz(temp) and s[temp.back().y]==s[v[i].y]) temp.back().x+=v[i].x;
            else temp.pb(v[i]);
        }
        v=temp;
        ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}