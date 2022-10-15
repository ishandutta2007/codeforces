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
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<int> b;
	for (int i = 1; i < n; ++i)
		if (a[i] <= a[i - 1])
			b.push_back(i);
	b.push_back(n);
	if (b.size() == 1) {
		cout << n << endl;
		return 0;
	}
	int res = 0;
	for (int j = 0; j + 1 < b.size(); ++j) {
		int ind = 0;
		int l1 = b[j];
		if (j)
			l1 -= b[j - 1];
		if (b[j] == n - 1) {
			res = max(res, l1 + 1);
			continue;
		}
		if (a[b[j] - 1] + 1 < a[b[j] + 1]) {
			res = max(res, l1 + b[j + 1] - b[j]);
		}
		else {
			res = max(res, l1 + 1);
			res = max(res, b[j + 1] - b[j] + 1);
		}
		if ((l1 > 1) && (a[b[j] - 2] + 1 < a[b[j]]))
			res = max(res, l1 + b[j + 1] - b[j]);
	}
	cout << res << endl;
	
	
	return 0;
}