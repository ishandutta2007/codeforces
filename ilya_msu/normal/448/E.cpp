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
#include<cassert>



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int mod = 1051131;
const ll N = 300100;

map<ll, vector<ll> > divisors;

void getDiv(ll x) {
	vector<ll> d;
	for (ll i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			d.push_back(i);
			if (i * i != x)
				d.push_back(x / i);
		}
	}
	//cerr << "-1" << endl;
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); ++i) {
		for (int j = 0; j <= i; ++j) {
			if (d[i] % d[j] == 0)
				divisors[d[i]].push_back(d[j]);
		}
		cerr << i << endl;
	}
}

int print;

void go(ll x, ll k) {
	if (print >= 100000)
		return;
	if ((x == 1) || (k == 0)) {
		cout << x << " ";
		++print;
		return;
	}
	for (int i = 0; i < divisors[x].size(); ++i)
		go(divisors[x][i], k - 1);
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	ll x, k;
	print = 0;
	cin >> x >> k;
	getDiv(x);
	go(x, k);
	cout << endl;

	return 0;
}