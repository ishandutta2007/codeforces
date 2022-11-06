#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	double ans = 1.0;
	int v = n+1;
	for(int i = m; i>=m-k; i--){
		ans*=i;
		ans/=v;
		v++;
	}
	cout << fixed << setprecision(10);
	cout << max(1-ans,(double)0) << "\n";
	return 0;
}