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
#define hell        10000000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,cl,ce,v,l[200005],e[200005],q;
void solve(){
    cin>>n>>m>>cl>>ce>>v;
    rep(i,0,cl){
        cin>>l[i];
    }
    rep(i,0,ce){
        cin>>e[i];
    }
    cin>>q;
    while(q--){
        int xx1,yy1,xx2,yy2;
        cin>>xx1>>yy1>>xx2>>yy2;
        if(xx1==xx2){
            cout<<abs(yy1-yy2)<<endl;
        }
        else{
            int d=upper_bound(l,l+cl,yy1)-l;
            int ans=hell;
            if(d<cl) ans=min(ans,(l[d]-yy1)+abs(xx1-xx2)+abs(l[d]-yy2));
            if(d) ans=min(ans,(yy1-l[d-1])+abs(xx1-xx2)+abs(l[d-1]-yy2));
            d=upper_bound(e,e+ce,yy1)-e;
            if(d<ce) ans=min(ans,(e[d]-yy1)+(abs(xx1-xx2)+v-1)/v+abs(e[d]-yy2));
            if(d) ans=min(ans,(yy1-e[d-1])+(abs(xx1-xx2)+v-1)/v+abs(e[d-1]-yy2));            
            cout<<ans<<endl;
        }
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