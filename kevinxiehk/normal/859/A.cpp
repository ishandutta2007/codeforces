#include <bits/stdc++.h>
#define ickbmi cout << "ick bmi 32.9\n";
#define ickorz cout << "cambridge cs undergrad orz\n";
#define ick cout << "ick orz\n";
#define DEBUG(x) cout << x << "\n";
using namespace std;
 
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	if (n > 25) {
		cout << a[n] - 25 << "\n";
		return 0;
	}
	else {
		if (a[n] <= 25) cout << "0\n";
		else cout << a[n] - 25 << "\n";
	}
}