#include <iostream>
#include <algorithm>
using namespace std;

int ans[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int p = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;	
		ans[i] = a + p;
		p = max(p, ans[i]);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}