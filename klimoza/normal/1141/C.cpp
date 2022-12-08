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

long double eps = 1e-8;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> q(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> q[i];
	}
	vector<ll> pref(n);
	ll mini = 0;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + q[i - 1];
		if (pref[mini] > pref[i]) mini = i;
	}
	vector<ll> p(n);
	p[0] = -pref[mini] + 1;
	set<ll> f;
	f.insert(p[0]);
	if (p[0] > n) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] + q[i - 1];
		if (p[i] > n || f.find(p[i]) != f.end()) {
			cout << -1 << endl;
			return 0;
		}
		f.insert(p[i]);
	}
	for (int i : p) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}