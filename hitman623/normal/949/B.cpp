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

void solve(){
    ll n,q;
    cin>>n>>q;
    while(q--){
    	ll x,cur=1;
    	vector<ll> ans;
    	cin>>x;
    	rep(r,0,62){
    		ll h=cur-1;
    		// 2*pos-1-(2*n-2*pos+1)*h=x
    		// 2*pos(1+h)-1-2*n*h-h=x
    		if((1+x+h-2*n)%(2+2*h)==0){
    			ans.pb(((1+x+h-2*n)/(2+2*h))+n);
    		}
    		cur*=2;
    	}
    	for(auto i:ans){
    		cout<<i<<endl;
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