#include <bits/stdc++.h>
using namespace std;
long long r, x, y, a, b, m, ans;
double mid;
int main(){
	cin >> r >> x >> y >> a >> b;
	r *= 2;
	m = (x - a) * (x - a) + (y - b) * (y - b);
	mid = sqrt(m);
	ans = mid / r;
	if(ans * r < mid){
		ans++;
	}
	cout << ans;
	return 0;
}