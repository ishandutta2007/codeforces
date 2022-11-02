#include <iostream>
#include <set>
using namespace std;
#define ll long long

ll a[200009], b[200009];
set<ll> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (ll i = 1; i * i <= 20000000000000LL; i++)
		st.insert(i * i);
	for (int i = 0; i < n / 2; i++) {
		cin >> a[i]; b[i * 2 + 1] = a[i];
	}
	ll s = 0, t = 1;
	for (int i = 0; i < n; i += 2) {
		while (t * t - s <= 0)
			t++;
		while (t * t <= 10000000000000LL) {
			ll r = t * t - s;
			if (st.find(s + r + a[i / 2]) != st.end()) {
				b[i] = r; s += b[i];
				break;
			}
			t++;
		}
		if (t * t > 10000000000000LL) {
			cout << "No" << '\n';
			return 0;
		}
		s += a[i / 2];
	}
	cout << "Yes" << '\n';
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << '\n';
	return 0;
}