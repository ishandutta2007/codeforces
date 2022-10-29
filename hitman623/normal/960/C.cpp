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
int x,d,cur=1,cnt;
vi v;
void solve(){
	cin>>x>>d;
	rep(i,0,30){
		if((x>>i)&1){
			cnt++;
			rep(j,0,i){
				v.pb(cur);
			}
			cur+=d+1;
		}
	}
	rep(i,0,cnt){
		v.pb(cur);
		cur+=d+1;
	}
	cout<<sz(v)<<endl;
	for(auto i:v){
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