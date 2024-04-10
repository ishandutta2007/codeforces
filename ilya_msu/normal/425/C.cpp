#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m, s, e, k;
vector<int> a, b;
vector<vector<int> > d;
vector<vector<int> > bb;
vector<int> res;

int find(int l, int v) {
	int up = bb[v].size();
	int down = -1;
	while(up - down > 1) {
		int mid = (up + down) / 2;
		if (bb[v][mid] >= l)
			up = mid;
		else
			down = mid;
	}
	if (up == bb[v].size())
		return INF;
	return bb[v][up];
}



void count() {
	bb.resize(N);
	res.resize(k + 1, INF);
	res[0] = 0;
	for (int i = 0; i < m; ++i)
		bb[b[i]].push_back(i);
	vector<vector<int> > mini(n, vector<int>(k + 1, INF));
	for (int i = 0; i < n; ++i)
		d[i][0] = 0, mini[i][0] = 0;
	for (int kk = 1; kk <= k; ++kk) {
		for (int i = kk - 1; i < n; ++i) {
			int x = 0;
			if (i)
				x = mini[i - 1][kk - 1];
			d[i][kk] = find(x, a[i]) + 1;
			if (i)
				mini[i][kk] = min(d[i][kk], mini[i - 1][kk]);
			else
				mini[i][kk] = d[i][kk];
			res[kk] = min(res[kk], d[i][kk] + i + 1);
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> s >> e;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	k = s / e;
	d.assign(n, vector<int>(k + 1, INF));
	count();
	int ans = 0;
	for (int i = 0; i <= k; ++i) {
		if (e * i + res[i] <= s)
			ans = i;
	}
	cout << ans << endl;


	return 0;
}