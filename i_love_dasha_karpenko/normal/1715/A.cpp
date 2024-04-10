//#prama GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
void solve(){
	int n,m;
	cin>>n>>m;
	int r1 = (n-1)*2+m-1+(m>1);
	int r2 = (m-1)*2+n-1+(n>1);
	cout<<min(r1,r2)<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}