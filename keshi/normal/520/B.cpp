#include <bits/stdc++.h>
using namespace std;
int ans, n, m;
int main(){
	cin >> n >> m;
	ans = 0;
	while (m > n){
		ans += 1 + m % 2;
		m = (m + 1) / 2;
	}
	cout << ans + n - m;
	return 0;
}