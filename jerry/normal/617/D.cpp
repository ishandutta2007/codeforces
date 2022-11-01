#include <bits/stdc++.h>
using namespace std;

bool two(int a1, int a2, int b1, int b2, int c1, int c2)
{
	if (a1 != b1) return false;
	if (a2 < c2 && c2 < b2) return false;
	if (b2 < c2 && c2 < a2) return false;
	return true;
}

int a1, a2, b1, b2, c1, c2;

bool two()
{
	if (two(a1, a2, b1, b2, c1, c2)) return true;
	if (two(a2, a1, b2, b1, c2, c1)) return true;
	if (two(a1, a2, c1, c2, b1, b2)) return true;
	if (two(a2, a1, c2, c1, b2, b1)) return true;
	if (two(b1, b2, a1, a2, c1, c2)) return true;
	if (two(b2, b1, a2, a1, c2, c1)) return true;
	if (two(b1, b2, c1, c2, a1, a2)) return true;
	if (two(b2, b1, c2, c1, a2, a1)) return true;
	if (two(c1, c2, a1, a2, b1, b2)) return true;
	if (two(c2, c1, a2, a1, b2, b1)) return true;
	if (two(c1, c2, b1, b2, a1, a2)) return true;
	if (two(c2, c1, b2, b1, a2, a1)) return true;
	return false;
}

int main()
{
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	if (a1 == b1 && a1 == c1) cout << 1 << endl;
	else if (a2 == b2 && a2 == c2) cout << 1 << endl;
	else if (two()) cout << 2 << endl;
	else cout << 3 << endl;
	return 0;
}