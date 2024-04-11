#include <bits/stdc++.h>

using namespace std;

bool cmp(const std::bitset<1001ul>& x, const std::bitset<1001ul>& y)
{
    for (int i = 1000; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

int main() {
	int n, s, t;
	cin >> n >> s;
	bitset<1001> a(0), b(0);

	for (int i = 0; i < n; i++) {
		cin >> t;
		a.set(i, t);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		b.set(i, t);
	}

  bitset<1001ul> g(0);
  g.set(s-1);
	if(a.test(0) && (a.test(s - 1) || (cmp(g, (a&b)) && b.test(s - 1)))) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}

}