#include <iostream>
#include <string>
using namespace std;

int n, k, ta[100009], a[100009];

bool wc(int s, int e, int p)
{
	for (int i = 0; i < n; i++) {
		ta[i] = a[i];
		if (s <= i && i <= e) ta[i] = p;
	}
	int mn[2] = { 100009, 100009 }, mx[2] = { -1, -1 };
	for (int i = 0; i < n; i++) {
		if (mn[ta[i]] > i) mn[ta[i]] = i;
		if (mx[ta[i]] < i) mx[ta[i]] = i;
	}
	if (mx[0] == -1 || mx[1] == -1) return true;
	if (mx[0] - mn[0] + 1 <= k || mx[1] - mn[1] + 1 <= k) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	string s; cin >> s;
	for (int i = 0; i < n; i++) 
		a[i] = s[i] - '0';
	if (wc(0, -1, 0)) {
		cout << "tokitsukaze" << '\n';
		return 0;
	}
	int mn[2] = { 100009, 100009 }, mx[2] = { -1, -1 };
	for (int i = 0; i < n; i++) {
		if (mn[a[i]] > i) mn[a[i]] = i;
		if (mx[a[i]] < i) mx[a[i]] = i;
	}
	if (mx[0] - mn[0] - 1 >= k || mx[1] - mn[1] - 1 >= k) {
		cout << "once again" << '\n';
		return 0;
	}
	if (wc(0, k - 1, 0) && wc(0, k - 1, 1) && wc(n - k, n - 1, 0) && wc(n - k, n - 1, 1)) {
		cout << "quailty" << '\n';
		return 0;
	}
	cout << "once again" << '\n';
	return 0;
}