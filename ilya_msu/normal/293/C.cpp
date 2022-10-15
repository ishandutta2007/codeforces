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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 10 + 10;
const int N = 1000 * 10000 + 10;



int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	if (n % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	n /= 3;
	ll up = sqrt((double)n) + 30;
	vector<ll> d;
	for (ll i = 1; i < up; ++i) {
		if (n % i == 0)
			d.push_back(i);
	}
	//cout << d.size() << endl;
	ll res = 0;
	for (int i = 0; i < d.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			ll d1 = d[i];
			ll d2 = d[j];
			ll d3 = n / d1 / d2;
			if (d1 * d2 * d3 == n) {
				if ((d3 < d2) && (d2 + d3 > d1) && ((d1 + d2 + d3) % 2 == 0))
					res += 6;
			}
		}
		ll d1 = d[i];
		ll d2 = d[i];
		ll d3 = n / d1 / d2;
		if ((d1 * d2 * d3 == n) && ((d1 + d2 + d3) % 2 == 0)) {
			if (d3 == d1)
				++res;
			else
				if (d3 < d1)
					res += 3;
				else
					if (d1 + d2 > d3)
						res += 3;
		}
	}
	cout << res << endl;

	
	return 0;
}