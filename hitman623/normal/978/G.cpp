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
int n,m,s[101],d[101],c[101],v[101];
vi ans;
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        cin>>s[i]>>d[i]>>c[i];
    }
    priority_queue<pair<int,pii>> pq;
    rep(i,1,n+1){
        int f=0;
        rep(j,0,m){
            if(d[j]==i){
                if(!v[j]){
                    cout<<-1<<endl;
                    return;
                }
                else{
                    ans.pb(m+1);
                    f=1;
                }
            }
            if(s[j]==i){
                pq.push({-d[j],{c[j],j}});
            }
        }
        if(f) continue;
        if(sz(pq)){
            auto dd=pq.top();
            pq.pop();
            ans.pb(dd.y.y+1);
            dd.y.x--;
            if(dd.y.x){
                pq.push(dd);
            }
            else{
                v[dd.y.y]=1;
            }
        }
        else{
            ans.pb(0);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
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