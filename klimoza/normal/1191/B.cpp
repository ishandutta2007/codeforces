#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

mt19937 mrand(random_device{} ());

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	
	map<pair<char, char>, int> cnt;
	string st;
	vector<pair<char, char>> a;
	while (cin >> st) {
		cnt[{st[0], st[1]}]++;
		a.push_back({ st[0], st[1] });
	}
	int n = size(a);
	int m = 3;
	for (auto st : a) {
		m = min(m, max(0, 3 - cnt[st]));
		m = min(m, max(0, 1 - cnt[{st.fi + 1, st.se}]) + max(0, 1 - cnt[{st.first + 2, st.second}]));
		m = min(m, max(0, 1 - cnt[{st.fi + 1, st.se}]) + max(0, 1 - cnt[{st.first - 1, st.second}]));
		m = min(m, max(0, 1 - cnt[{st.fi - 1, st.se}]) + max(0, 1 - cnt[{st.first - 2, st.second}]));
	}
	cout << m << endl;
	return 0;
}