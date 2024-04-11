#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;
const lint mod = 1e9 + 7;

int n;
pi a[1005];

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int main(){
	cin >> n;
	for(int i=n-1; i>=0; i--){
		cin >> a[i].first >> a[i].second;
	}
	a[n+1] = a[1];
	a[n] = a[0];
	long double ans = 1e18;
	for(int i=0; i<n; i++){
		lint c = ccw(a[i], a[i+1], a[i+2]);
		ans = min(ans, (long double)c / hypot(a[i+2].first - a[i].first, a[i+2].second - a[i].second));
	}
	printf("%.10Lf\n", ans/2);
}