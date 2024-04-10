#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
int F(int x){
	int ret = 0;
	while(x){
		ret += 1;
		x/=10;
	}
	return ret;
}
void solve() {
	int n;
	cin>>n;
	map<int,int> M;
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		M[val] += 1;
	}
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		M[val] -= 1;
	}
	int ans = 0;
	while(!M.empty()){
		auto it = M.rbegin();
		if (it->second!=0){
			ans += abs(it->second);
			M[F(it->first)] += it->second;
		}
		M.erase(prev(M.end()));
	}
	cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}