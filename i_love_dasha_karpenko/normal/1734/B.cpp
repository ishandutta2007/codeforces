#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 507;
void solve(){
	int n;
	cin>>n;
	for(int lvl = 1;lvl<=n;lvl+=1){
		for(int i = 1;i<=lvl;i+=1){
			cout<<(i==1 || i==lvl)<<' ';
		}
		cout<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}