#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int pa = 0, pb = 0, ans = 1;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (max(pa, pb) < min(a, b)) {
			ans += min(a, b) - max(pa, pb);
			if (pa != pb)
				ans++;
		}
		else if (max(pa, pb) == min(a, b) && min(pa, pb) < min(a, b))
			ans++;
		pa = a; pb = b;
	}
	cout << ans << '\n';
	return 0;
}