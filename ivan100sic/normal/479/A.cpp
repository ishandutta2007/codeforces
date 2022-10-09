#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int m = 0;
	m = max(m, a+b*c);
	m = max(m, a+b+c);
	m = max(m, a*b+c);
	m = max(m, a*b*c);

	m = max(m, (a+b)*c);
	m = max(m, a*(b+c));

	cout << m;
}