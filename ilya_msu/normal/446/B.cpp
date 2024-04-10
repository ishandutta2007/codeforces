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
typedef unsigned long long ull; 

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 10;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m, k, p;
	cin >> n >> m >> k >> p;
	vector<vector<ll> > a(n, vector<ll>(m));
	vector<ll> r(n, 0), c(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}

	vector<ll> sr(k + 1, -LLINF), sc(k + 1, -LLINF);
	sr[0] = sc[0] = 0;
	priority_queue<ll> qr;
	for (int i = 0; i < n; ++i)
		qr.push(r[i]);
	for (int i = 0; i < k; ++i) {
		ll v = qr.top();
		qr.pop();
		sr[i + 1] = max(sr[i + 1], sr[i] + v);
		v -= m * p;
		qr.push(v);
	}
	priority_queue<ll> qc;
	for (int i = 0; i < m; ++i)
		qc.push(c[i]);
	for (int i = 0; i < k; ++i) {
		ll v = qc.top();
		qc.pop();
		sc[i + 1] = max(sc[i + 1], sc[i] + v);
		v -= n * p;
		qc.push(v);
	}
	ll res = sr[k];
	for (ll i = 0; i < k; ++i) {
		ll cur = sr[i] + sc[k - i] - i * p * (k - i);
		res = max(res, cur);
	}
	cout << res << endl;
	
    return 0;
}