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
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 20 * 1000 + 10;
const ll MOD = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int res = a[0];
	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			vector<int> b, c;
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				if ((i >= l) && (i <= r)) {
					b.push_back(a[i]);
					sum += a[i];
				}
				else
					c.push_back(a[i]);
			}
			sort(b.begin(), b.end());
			sort(c.begin(), c.end());
			reverse(c.begin(), c.end());
			for (int i = 0; (i < k) && (i < b.size()) && (i < c.size()); ++i) {
				if (c[i] > b[i]) {
					sum += c[i];
					sum -= b[i];
				}
				else
					break;
			}
			res = max(res, sum);
		}
	}
	cout << res << endl;
	
	return 0;
}