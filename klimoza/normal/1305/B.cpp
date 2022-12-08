#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void solve() {	
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> f;
	vector<int> t1, t2;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') t1.push_back(i);
		else t2.push_back(i);
	}
	while (!t1.empty() && !t2.empty() && t1[0] < t2.back()) {
		int cnt = t1.size() -1 ;
		f.push_back(vector<int>());
		for (int i = 1; i < t1.size(); i++) {
			int id = t2.size() - i - 1;
			//cout << i << " " << id << endl;
			if (id < 0 || t2[id] < t1[i]) {
				cnt = i - 1;
				break;
			}
		}
		int id = t2.size() - cnt - 1;
		//cout << cnt << " " << t1.size() << " " << t2.size() << endl;
		vector<int> f1(t1.size() - (cnt + 1)), f2(t2.size() - (cnt + 1));
		for (int i = cnt + 1; i < t1.size(); i++) {
			f1[i - cnt - 1] = t1[i];
		}
		for (int i = 0; i <= cnt; i++)
			f.back().push_back(t1[i]);
		int kek = 0;
		for (int i = id; i <= id + cnt; i++)
			f.back().push_back(t2[i]);
		for (int i = 0; i < id; i++)
			f2[kek] = t2[i], kek++;
		for (int i = id + (cnt + 1); i < t2.size(); i++)
			f2[kek] = t2[i], kek++;
		t1 = f1;
		t2 = f2;
	}
	cout << f.size() << endl;
	for (auto u : f) {
		cout << u.size() << endl;
		for (int i : u)
			cout << i + 1 << " ";
		cout << endl;
	}
	return;
}