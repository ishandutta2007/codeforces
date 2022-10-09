#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b;
	cin >> a >> b;
	a = abs(a-b);

	int x = a/2;
	int y = a-x;
	cout << (x*(x+1)+y*(y+1)) / 2 << '\n';	
}