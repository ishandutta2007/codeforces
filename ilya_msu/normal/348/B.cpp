#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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

 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const ll INF = (ll)1000 * 1000 * 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
vector<vector<int> > g;
vector<int> a;
vector<ll> sum, di;

ll gcd(ll x, ll y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

ll nok(ll x, ll y) {
	ll d = gcd(x, y);
	/*if (d == 0) {
		cout << "1";
		return 1;
	}*/
	ll xx = x / d;
	ll res = xx * y;
	/*if (xx == 0) {
		cout << "2";
		return 1;
	}*/
	if ((res >= 0) && (res % xx == 0) && (res / xx == y))
		return res;
	return -1;
}

void dfs(int pos, int prev = -1) {
	sum[pos] = a[pos];
	ll m = INF;
	ll count = 0;
	ll xx = 1;
	for (int i = 0; i < g[pos].size(); ++i) {
		int to = g[pos][i];
		if (to == prev)
			continue;
		dfs(to, pos);
		++count;
		//sum[pos] += sum[to];
		m = min(m, sum[to]);
		/*if (di[to] == 0)
			cout << "!" << endl;*/
		xx = nok(abs(xx), abs(di[to]));
		if (xx == -1)
			m = 0;
	}
	if (count == 0)
		return;
	/*if (xx == 0) {
		cout << "3\n";
		return ;
	}*/
	if (m == 0)
		sum[pos] = 0, di[pos] = 1;
	else {
	sum[pos] = (m / xx * xx) * count;
	di[pos] = xx * count;
	}
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	g.resize(n);
	a.resize(n);
	sum.assign(n, 0);
	di.assign(n, 1);
	ll all = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		all += a[i];
	}
	int f, s;
	for (int i = 0; i + 1 < n; ++i) {
		scanf("%d %d", &f, &s);
		--f, --s;
		g[f].push_back(s);
		g[s].push_back(f);
	}
	dfs(0);
	cout << all - sum[0] << endl;

    
    return 0;
}