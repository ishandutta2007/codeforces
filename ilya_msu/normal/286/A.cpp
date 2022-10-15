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
const int INF = 1000 * 1000;
//const int N = 300;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int k = n % 4;
	if ((k == 2) || (k == 3)) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans(n + 1);
	int q = n / 4;
	for (int i = 1; i <= q; ++i) {
		ans[2 * i - 1] = 2 * i;
		ans[2 * i] = n + 1 - 2 * i + 1;
		ans[n + 1 - 2 * i + 1] = n + 1 - 2 * i;
		ans[n + 1 - 2 * i] = 2 * i - 1;
	}
	if (k == 1)
		ans[(n + 1) / 2] = (n + 1) / 2;
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}