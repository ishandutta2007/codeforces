#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int s = 0, e = n + 1, md = (s + e) / 2;
	while (s < e) {
		md = (s + e) / 2;
		int a = 1000000000, b = a;
		if (1 <= md && md <= n) {
			cout << "? " << md << endl;
			cin >> a;
		}
		if (md + 1 <= n) {
			cout << "? " << md + 1 << endl;
			cin >> b;
		}
		if (a > b) s = md + 1;
		else e = md;
	}
	md = (s + e) / 2;
	cout << "! " << md << endl;
	return 0;
}