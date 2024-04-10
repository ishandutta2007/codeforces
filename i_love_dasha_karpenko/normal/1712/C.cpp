#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
const int N = 1e5+7;
bool vis[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		vis[i] = 0;
	}
	set<int> S;
	int res = 0;
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		if (vis[val]){
			val = 0;
		}
		if(!S.empty() && *S.rbegin()>val){
			for(int to:S){
				vis[to] = 1;
				res += 1;
			}
			S.clear();
			if (vis[val]){
				val = 0;
			}
		}
		if (val!=0){
			S.insert(val);
		}
	}
	cout<<res<<endl;
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}