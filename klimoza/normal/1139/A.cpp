#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string st;
	ll ans = 0;
	cin >> st;
	for (int i = 0; i < n; i++) {
		if ((st[i] - '0') % 2) continue;
		ans += i + 1;
	}
	cout << ans << endl;
	return 0;
}