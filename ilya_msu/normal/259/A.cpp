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
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 1000 * 1000 * 1000 + 10;

int f(int x, int k) {
	int c = 0;
	while (x) {
		int xx = x % 10;
		if ((xx == 4) || (xx == 7))
			++c;
		x /= 10;
	}
	return c <= k;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> ss(8);
	for (int i = 0; i < 8; ++i)
		cin >> ss[i];
	for (int i = 0; i < 8; ++i) {
		for (int j = 1; j < 8; ++j)
			if (ss[i][j] == ss[i][j - 1]) {
				cout << "NO" << endl;
				return 0;
			}
	}
	cout << "YES" << endl;
	return 0;
}