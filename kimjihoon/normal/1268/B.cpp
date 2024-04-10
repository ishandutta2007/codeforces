#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ans += a / 2; a = a % 2;
		if (v.empty()) v.push_back(a);
		else {
			if (v.back() == a) { ans += a; v.pop_back(); }
			else v.push_back(a);
		}
	}
	cout << ans << '\n';
	return 0;
}