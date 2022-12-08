#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	ll n, b, a;
	cin >> n >> b >> a;
	int cur_a = a;
	vector<int> f(n);
	for (int i = 0; i < n; i++) cin >> f[i];
	bool fl = true;
	for (int i = 0; i < n; i++) {
		if (b == 0 && cur_a == 0) {
			cout << i << endl;
			fl = false;
			break;
		}
		else {
			if (b == 0 && cur_a > 0) cur_a--;
			else if (b > 0 && cur_a == 0) {
				b--;
				cur_a += f[i];
			}
			else if (cur_a == a) cur_a--;
			else if (f[i] == 1) {
				b--;
				cur_a += f[i];
			}
			else cur_a--;
		}
	}
	if (fl) cout << n << endl;
	//system("pause");
	return 0;
}