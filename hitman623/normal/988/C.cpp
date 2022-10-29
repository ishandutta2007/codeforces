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
int k,n[200005],s[200005];
vi v[200005];
map<int,vii> mp;
void solve(){
    cin>>k;
    rep(i,0,k){
        cin>>n[i];
        rep(j,0,n[i]){
            int x;
            cin>>x;
            v[i].pb(x);
            s[i]+=x;
        }
        rep(j,0,n[i]){
            mp[s[i]-v[i][j]].pb({i,j});
        }
    }
    for(auto i:mp){
        set<int> st;
        rep(j,0,sz(i.y)){
            st.insert(i.y[j].x);
        }
        if(sz(st)>1){
            int cnt=2;
            st.clear();
            cout<<"YES"<<endl;
            for(auto j:i.y){
                if(st.find(j.x)==st.end() and cnt){
                    cout<<j.x+1<<" "<<j.y+1<<endl;
                    st.insert(j.x);
                    cnt--;
                }
            }
            return;
        }
    }
    cout<<"NO"<<endl;
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