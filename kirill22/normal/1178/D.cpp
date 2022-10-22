#include <bits/stdc++.h>

using namespace std;

#define int long long

bool f(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

signed main() {
    int n;
    cin >> n;
    int ans = 0;
    while (ans <= n / 2) {
    	if (f(n + ans)) {
    		break;
    	}
    	ans++;
    }
    if (ans > n / 2) {
    	cout << -1;
    	return 0;
    }
    cout << n + ans << endl;
    for (int i = 1; i <= n; i++) {
    	if (i < n) {
    		cout << i << " " << i + 1 << endl;
    	} else {
    		cout << n << " " << 1 << endl;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	if (ans < 1) break;
    	if (i % 4 == 1 || i % 4 == 2) { 
    		cout << i << " " << i + 2 << endl;
    		ans--;
    	}
    }
    
}