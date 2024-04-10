#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
double eps = 1e-12;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string st1, st2;
	cin >> st1 >> st2;
	vector<int> c(n);
	for (int i = 0; i < n; i++) c[i] = st1[i] - '0';
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = st2[i] - '0';
	int cnt0= 0 , cnt1 = 0 , cnt2 = 0, cnt3=0;
	for (int i = 0; i < n; i++) {
		if (c[i] && !a[i]) cnt1++;
		else if (!c[i] && a[i]) cnt2++;
		else if (c[i] && a[i]) cnt3++;
		else cnt0++;
	}
	int x=0, y=0, z=0, w=0;
	w = min(min(cnt3, (cnt2 + cnt3) / 2), n / 2);
	x = w + n / 2 - cnt2 - cnt3;
	//cout << w << " " << x << endl;
	if (x > cnt0) {
		w -= (x - cnt0);
		x = cnt0;
	}
	else if (x < 0) {
		cout << -1 << endl;
		return 0;
	}
	if (w < 0) {
		cout << -1 << endl;
		return 0;
	}
	bool fl = false;
	for (int i = 0; i <= cnt1; i++) {
		z = n / 2 - w - i - x;
		if (z <= cnt2 && z >= 0 && i + z + 2 * w == cnt2 + cnt3){
			y = i;
			fl = true;
			break;
		}
	}
	if (!fl) {
		cout << -1 << endl;
	}
	else {
		//cout << y << " " << x << " " << z << " " << w << endl;
		for (int i = 0; i < n; i++) {
			if (c[i] && !a[i] && y) {
				cout << i + 1 << " ";
				y--;
			}
			else if (!c[i] && a[i] && z) {
				cout << i + 1 << " ";
				z--;
			}
			else if (c[i] && a[i] && w) {
				cout << i + 1 << " ";
				w--;
			}
			else if(!c[i] && !a[i] && x){
				cout << i + 1 << " ";
				x--;
			}
		}
	}
	//system("pause");
	return 0;
}