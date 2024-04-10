#include <iostream>
using namespace std;

int md = 1000000007;

int fb(int n)
{
	int a = 1, b = 1;
	for (int i = 1; i < n; i++) {
		int t = a + b; a = b; b = t;
		b = b % md;
	}
	return (b * 2) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	cout << (fb(n) + fb(m) - 2) % md << '\n';	
	return 0;
}