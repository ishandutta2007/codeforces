#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
	}
	int ans = 0;
	multiset<int> b;
	b.insert(0);
	int j = 1;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
        while (b.find(pref[i]) != b.end()) {
            b.erase(b.find(tmp));
            tmp += a[j - 1];
            b.insert(tmp);
            b.erase(b.find(pref[j]));
            j++;
        }
        b.insert(pref[i]);
        ans += i - j + 1;
        //cout << j << endl;
	}
	cout << ans;
}