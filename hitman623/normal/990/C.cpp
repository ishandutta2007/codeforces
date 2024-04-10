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
ll ans;
string s;
mi open,close;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>s;
        int cur=0,f=1;
        for(auto j:s){
            if(j=='(') cur++;
            else cur--;
            if(cur<0) f=0;
        }
        if(f){
            open[cur]++;
        }
        reverse(all(s));
        rep(j,0,sz(s)){
            if(s[j]==')') s[j]='(';
            else s[j]=')';
        }
        cur=0,f=1;
        for(auto j:s){
            if(j=='(') cur++;
            else cur--;
            if(cur<0) f=0;
        }
        if(f){
            close[cur]++;
        }
    }
    for(auto i:open){
        ans+=1LL*i.y*close[i.x];
    }
    cout<<ans<<endl;
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