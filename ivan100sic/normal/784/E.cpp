#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int u1 = a ^ b;
	int u2 = c | d;
	int u3 = b & c;
	int u4 = a ^ d;

	int v1 = u1 & u2;
	int v2 = u3 | u4;

	cout << (v1 ^ v2) << '\n';
}