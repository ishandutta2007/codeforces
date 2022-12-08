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
	
	ll a, b, c;
	cin >> a >> b >> c;
	ll week = min(min(a / 3, b / 2), c / 2);
	a -= 3 * week; b -= 2 * week; c -= 2 * week;
	ll cnt = 7 * week;
	ll maxi = 0;
	for (int i = 0; i < 7; i++) {
		ll cur = 0;
		ll cur_a = a;
		ll cur_b = b;
		ll cur_c = c;
		for (int j = i; j < i + 7; j++) {
			int f = (j % 7);
			if (f == 0 || f == 3 || f == 6) cur_a--;
			else if (f == 1 || f == 5) cur_b--;
			else cur_c--;
			if (cur_a < 0 || cur_b < 0 || cur_c < 0) break;
			cur++;
		}
		maxi = max(maxi, cur);
	}
	cout << maxi + cnt << endl;
	//system("pause");
	return 0;
}