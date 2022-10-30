// Hydro submission #631ef33632ae6c3198c8cdc3@1662972727744
#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n, m, a;
	cin >> n >> m >> a;
	int num, num1;
	if (n % a == 0) {
		num = n / a;
	} else {
		num = n / a + 1;
	}
	if (m % a == 0) {
		num1 = m / a;
	} else {
		num1 = m / a + 1;
	}
	cout << 1ll * num * num1;
	
	return 0;
}