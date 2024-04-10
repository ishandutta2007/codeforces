#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const string ans[2] = {"Furlo", "Rublo"};

int n;
ll a[maxn];
vector<pair<ll, int> > gr;

bool reading() {
	if (!(cin >> n)) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	return 1;
}

string solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res ^= gr[lower_bound(gr.begin(), gr.end(), make_pair(a[i], inf)) - gr.begin() - 1].second;
	}
	return ans[!res];
}

//int gr[5000000];

int mex(vector<int> v) {
	sort(v.begin(), v.end());
	int cur = 0;
	for (int i = 0; i < inf; i++) {
		if (cur < v.size() && v[cur] == i) while (cur < v.size() && v[cur] == i) cur++;
		else return i;
	}
}

/*vector<int> v;

int getgr(ll x) {
	v.clear();
	for (int y = sqrt(x + 0.5); 1LL * y * y <= x && 1LL * y * y * y * y >= x && y < x; y--) 
		v.push_back(gr[y]);
	return mex(v);
}*/

ll sqr(ll x) {
	return x * x;
}

int getgr(vector<pair<ll, int> > v, int l, int r) {
	vector<int> a;
	for (int i = l; i <= r; i++) a.push_back(v[i].second);
	return mex(a);
}

void lol(bool f) {
	if (!f) return;

	gr.push_back(make_pair(1, 0));
	gr.push_back(make_pair(4, 1));
	int curl = 1, curr = 1;

	while (gr.back().first < 1e12) {
		ll a1 = sqr(sqr(gr[curl].first - 1)) + 1, a2 = sqr(gr[curr].first);
		ll nw = min(a1, a2);
		int o = getgr(gr, curl - (a1 != nw), curr - (a2 != nw));
		gr.push_back(make_pair(nw, o));
		if (a1 == nw) curl++;
		if (a2 == nw) curr++;
	}
	//for (int i = 0; i < gr.size(); i++) cout << gr[i].first << " " << gr[i].second << endl;
	/*gr[0] = 0;
	for (int i = 1; i <= 10000; i++) {
		gr[i] = getgr(i);
		cerr << i << "\n";
	}
	for (int i = 0; i <= 10000; i++) cout << i << " " << gr[i] << endl;*/
	//exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	lol(1);
	while (reading()) cout << solve() + "\n";

	return 0;
}