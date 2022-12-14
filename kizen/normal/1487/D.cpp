#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long x = sqrt(n * 2 - 1);
		while(((x + 1) * (x + 1) + 1) / 2 <= n){
			++x;
		}
		cout << (x + 1) / 2 - 1 << '\n';
	}
	return 0;
}