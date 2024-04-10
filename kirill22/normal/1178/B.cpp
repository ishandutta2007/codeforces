#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;
    int an = 0;
    int n = s.size();
    int tmp = 0, ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'v') {
    		tmp++;
    	} else {
    		tmp = 0;
    	}
    	if (tmp > 1) {
    		ans++;
    	}
    	a[i] = ans;
    }
    ans = 0;
    tmp = 0;
    for (int i = 0; i < n; i++) {
    	if (s[n - 1 - i] == 'v') {
    		tmp++;
    	} else {
    		tmp = 0;
    	}
    	if (tmp > 1) {
    		ans++;
    	}
    	b[n -  1 - i] = ans;
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'o') {
    		an += a[i] * b[i];
    	}
    }
    cout << an;
}