#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

int r, g, b, ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> g >> b;
	for(int i = 1; i < 101; i++) {
		if(r >= i && g >= (i + 1) && b >= (i + 2))
			ans = 3 * i + 3;
	}
	cout << ans;
}