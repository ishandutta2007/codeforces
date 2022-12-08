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

vector<char> a;

bool check(int ind) {
	int n = a.size();
	int t = n % 2;
	for (int i = ind + 1; i <= ind + n / 2; i++) {
		//cout << i << " " << (ind - (i - ind - 1) + n) % n << " " << ind << " dasd " << endl;
		if (a[i] != a[(ind - (i - ind - 1) + n) % n]) return false;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != a[(i + ind + 1) % n]) return true;
		//cout << i << " " << (i + ind) % n << endl;
	}
	return false;

}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string st;
	cin >> st;
	int n = st.size();
	a.resize(n);
	for (int i = 0; i < n; i++) a[i] = st[i];
	bool fl = false;
	for (int i = 1; i < n / 2; i++) {
		if (a[i] != a[i - 1]) {
			fl = true;
			break;
		}
	}
	if (!fl) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < n / 2; i++) {
		if (check(i)) {
			cout << 1 << endl;
			//cout << i << endl;
			//system("pause");
			return 0;
		}
	}
	cout << 2 << endl;
	//system("pause");
	return 0;
}