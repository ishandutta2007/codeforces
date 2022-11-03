#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
	ios_base::sync_with_stdio(false);
	ll x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	b += a;
	c += b;
	y += x;
	z += y;
	if (x <= a && y <= b && z <= c) {
		cout << "YES\n";
	}else{ 
		cout << "NO\n";
	}


}