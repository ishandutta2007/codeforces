#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,l,m,a[100005];
void solve(){
    cin>>n>>k>>l;
    m=n*k;
    rep(i,0,m){
        cin>>a[i];
    }
    sort(a,a+m);
    if(abs(a[0]-a[n-1])>l){
        cout<<0<<endl;
        return ;
    }
    priority_queue<int,vi, greater<int>> pq;
    priority_queue<int> v;
    rep(i,0,m){
        if(a[i]>a[0]+l) break;
        pq.push(a[i]);
    }
    int ans=0;
    rep(i,0,n){
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        else{
            ans+=v.top();
            v.pop();
        }
        rep(j,0,k-1){
            if(!pq.empty()){
                v.push(pq.top());
                pq.pop();
            }
        }
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