#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
using lint = long long;
using pi = pair<lint, lint>;

int n, x, y, d;
lint f(int x, int y, int d){
	if(y == 1 || y == n){
		return (abs(x - y) + d - 1) / d;
	}
	int w = abs(x - y);
	if(w % d) return 1e11;
	return w / d;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> x >> y >> d;
		lint ans =  min({
			f(x, y, d),
			f(x, n, d) + f(n, y, d),
			f(x, 1, d) + f(1, y, d),
			f(x, 1, d) + f(1, n, d) + f(n, y, d),
			f(x, n, d) + f(n, 1, d) + f(1, y, d)});
		if(ans > 1e10) ans = -1;
		cout << ans << endl;
	}
}