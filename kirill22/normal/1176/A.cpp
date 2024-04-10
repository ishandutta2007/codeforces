#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int q;
	cin >> q;
	while(q--){
		int a = 0, b = 0, c = 0;
		int n;
		cin >> n;
		while(n % 2 == 0){
			a++;
			n /= 2;
		}
		while(n % 3 == 0){
			b += 2;
			n/= 3;
		}
		while(n % 5 == 0){
			c += 3;
			n/= 5;
		}
		if(n == 1){
			cout << a + b  + c << endl;
		}
		else{
			cout << -1;
			cout << endl;
		}
	}
}