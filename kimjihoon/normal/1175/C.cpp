#include <iostream>
using namespace std;

int n, k, a[200009], x;

bool ps(int d)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < i && a[j] < a[i] - 2 * d)
			j++;
		if (i - j >= k) {
			x = a[i] - d;
			return true;
		}
	}
	return false;
}

int bs(int s, int e)
{
	int md = (s + e) / 2;
	if (s >= e) return md;
	if (ps(md)) return bs(s, md);
	return bs(md + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ps(bs(0, 1000000009));
		cout << x << '\n';
	}
	return 0;
}