#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 2 * (n + 1);
	for(int i = 1; i <= n; i++){
		ans = min(ans, 2 * (i + 1 + (n - 1) / i));
	}
	cout << ans;
}