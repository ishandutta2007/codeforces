#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    int sum = 0, sum2 = 0;
    vector<int> a(n);
    int k = 0;
    for (int i= 0;i < n; i++) {
    	cin >> a[i];
    	sum += a[i];
    	if (a[0] >= 2 * a[i] || i == 0) {
    		sum2 += a[i];
    		k++;
    	}
    }
    if (sum2 <= (sum) / 2) {
    	cout << 0;
    	return 0;
    }
    cout << k << endl;
    for (int i= 0;i < n; i++) {
    	if (a[0] >= 2 * a[i] || i == 0) {
    		cout << i + 1 << " ";
    	}
    }
}