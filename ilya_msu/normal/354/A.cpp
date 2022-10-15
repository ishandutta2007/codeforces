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
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 9;
const long double eps = 1e-10;


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n, l, r, ql, qr; 
	cin >> n >> l >> r >> ql >> qr;
	vector<int> w(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &w[i]);
	vector<int> sum(n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + w[i - 1];
	int res = 2 * INF + 100000;
	for (int i = 0; i <= n; ++i) {
		int cur = sum[i] * l + (sum[n] - sum[i]) * r;
		int add = 0;
		if (i * 2 + 1 < n) {
			add += (n - 2 * i - 1) * qr;
		}
		int j = n - i;
		if (2 * j + 1 < n)
			add += (n - 2 * j - 1) * ql;
		res = min(res, cur + add);

	}
	cout << res << endl;
    return 0;
}