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
#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;



int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	int m = 10000;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i)
			m = min(m, abs(a[i]));
	}
	m += 5;
	vector<int> s(n);
	s[0] = a[0];
	for (int i = 1; i < n; ++i)
		s[i] = s[i - 1] + a[i];
	int res = a[1] * a[1] + 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; (j < n) && (j <= i + m); ++j) {
			int d1 = j - i;
			int d2 = abs(s[j] - s[i]);
			if (d2 > m)
				continue;			
			res = min(res, d1 * d1 + d2 * d2);
		}
	cout << res << endl;
    return 0;
}