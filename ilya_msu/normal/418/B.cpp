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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;

struct Friend {
	ll mon, cost;
	vector<ll> pr;
	ll code;
};

bool operator<(const Friend& a, const Friend& b) {
	return (a.mon < b.mon);
}

int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m, b;
	cin >> n >> m >> b;
	vector<Friend> fr(n);
	for (int i = 0; i < n; ++i) {
		cin >> fr[i].cost >> fr[i].mon;
		int sz;
		cin >> sz;
		fr[i].pr.resize(sz);
		fr[i].code = 0;
		for (int j = 0; j < sz; ++j) {
			cin >> fr[i].pr[j];
			fr[i].code += (1 << (fr[i].pr[j] - 1));
		}
	}
	sort(fr.begin(), fr.end());
	ll res = LLINF;
	int up = 1 << m;
	vector<ll> d(up, LLINF);
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		ll cur = fr[i].mon * b;
		for (int j = up - 1; j >= 0; --j) {
			int pos = j | fr[i].code;
			d[pos] = min(d[pos], d[j] + fr[i].cost);
		}
		cur += d[up - 1];
		res = min(res, cur);
	}
	if (res == LLINF)
		cout << -1 << endl;
	else
		cout << res << endl;
    return 0;
}