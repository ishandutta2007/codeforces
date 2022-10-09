#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[8] = {0, 52, 52, 52, 52, 53, 53, 52};
int q[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x;
	string a, b;
	cin >> x >> a >> b;

	if (b == "week")
		cout << p[x];
	else {
		cout << count_if(q+1, q+13, [&](int y) { return x <= y; }) << '\n';
	}
}