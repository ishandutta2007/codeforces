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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> po(m);
	vector<int> sc(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> sc[i]; sc[i]--;
		po[sc[i]] = max(po[sc[i]], p[i]);
	}
	int tot = 0;
	int t;
	for (int i = 0; i < k; i++) {
		cin >> t; t--;
		if (po[sc[t]] != p[t]) tot++;
	}
	cout << tot << endl;
	//system("pause");
	return 0;
}