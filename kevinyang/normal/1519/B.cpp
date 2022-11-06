#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		int low = (n-1)+n*(m-1);
		int high = (m-1)+m*(n-1);
		if(low>high)swap(low,high);
		if(k>=low&&k<=high)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}