#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int b, k; cin >> b >> k;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		if (a % 2 == 1 && (i == k - 1 || b % 2 == 1)) ans++;
	}
	if (ans % 2 == 0) cout << "even" << '\n';
	else cout << "odd" << '\n';
	return 0;
}