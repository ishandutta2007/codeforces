#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	int x = min(k2, min(k5, k6));

	ll ans = ll(x) * ll(256);

	k2 -= x;
	x = min(k2, k3);
	ans += ll(x) * ll(32);

	cout << ans << "\n";

}