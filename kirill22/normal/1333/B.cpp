#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        bool f = true;
        int f1 = 0, f2 = 0;
        for (int i = 0; i < n; i++) {
            bool fi = false;
            if (a[i] == b[i]) fi = true;
            if (a[i] < b[i] && f1) fi = true;
            if (a[i] > b[i] & f2) fi = true;
            if (!fi) f = false;
            if (a[i] == 1) f1 = 1;
            if (a[i] == -1) f2 = 1;
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
	}
}