#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<ll> a;
ll sol;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		a.insert(x);
	}	

	while (a.size() > 1) {
		if (a.size() % 2 == 0) {
			ll x = *a.begin();
			a.erase(a.begin());
			ll y = *a.begin();
			a.erase(a.begin());
			a.insert(x+y);
			sol += x+y;		
		} else {
			ll x = *a.begin();
			a.erase(a.begin());
			ll y = *a.begin();
			a.erase(a.begin());
			ll z = *a.begin();
			a.erase(a.begin());
			a.insert(x+y+z);
			sol += x+y+z;		
		}
	}
	cout << sol;
}