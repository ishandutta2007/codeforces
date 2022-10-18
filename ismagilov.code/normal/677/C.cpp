#include <bits/stdc++.h>
using namespace std;

int norm(int a){
	int ans = 0;
	for (int i = 0; i < 64; i++){
		for (int j = 0; j < 64; j++){
			if (((i & j) == a)){
				ans++;
				//cout << i << ' ' << j << endl;
			}
		}
	}	
	//cout << ans;
	return ans;
}

main() {
	string a;
	cin >> a;
	int m[a.size()];
	int k[64];
	for (int i = 0; i < 64; i++){
		k[i] = norm(i);
	}
	for (int i = 0; i < a.size(); i++){
		
		if (a[i] >= '0' && a[i] <= '9'){
			m[i] = a[i] - '0';
		}
		if (a[i] >= 'A' && a[i] <= 'Z'){
			m[i] = a[i] - 'A' + 10;
		}
		if (a[i] >= 'a' && a[i] <= 'z'){
			m[i] = a[i] - 'a' + 36;
		}
		if (a[i] == '-'){
			m[i] = 62;
		}
		if (a[i] == '_'){
			m[i] = 63;
		}
	}
	long long ans = 1;
	for (int i = 0; i < a.size(); i++){
		ans *= k[m[i]];
		ans = ans % 1000000007;
	}
	cout << ans;
}