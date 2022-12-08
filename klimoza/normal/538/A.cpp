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
ll mod = 998244353;



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string st;
	cin >> st;
	bool fl = false;
	int n = st.size();
	string h = "CODEFORCES";
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string g = "";
			for (int k = 0; k < i; k++) {
				g += st[k];
			}
			for (int k = j + 1; k < n; k++) {
				g += st[k];
			}
			if (g == h) {
				fl = true;
				break;
			}
		}
		if (fl) {
			break;
		}
	}
	if (fl) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}