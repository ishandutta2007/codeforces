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

int zero = 0;
int one = 0;
int n;
int glo = 0;

void check(int l, int r, int tot) {
	//cout << l << " " << r << " " << tot << endl;
	int mid = (l + r) / 2;
	cout << "? ";
	for (int i = 0; i < l; i++) cout << "0";
	for (int i = l; i < mid; i++) cout << "1";
	for (int i = mid; i < n; i++) cout << "0";
	cout << endl;
	int f;
	cin >> f;
	f = (mid - l + glo - f) / 2	;
	//cout << f << endl;
	bool fl1 = false, fl2 = false;
	if (f == mid - l) {
		one = l + 1;
		fl1 = true;
	}
	if (f == 0) {
		zero = l + 1;
		fl1 = true;
	}
	if (f == tot) {
		zero = mid + 1;
		fl2 = true;
	}
	if (r - mid == tot - f) {
		one = mid + 1;
		fl2 = true;
	}
	if (fl1 && fl2) return;
	else if (fl1) check(mid, r, tot - f);
	else check(l, mid, f);
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	cout << "? ";
	for (int i = 0; i < n; i++) cout << "0";
	cout << endl;
	int tot;
	cin >> tot;
	glo = tot;
	check(0, n, tot);
	cout << "! " << zero << " " << one << endl;
	//system("pause");
	return 0;
}