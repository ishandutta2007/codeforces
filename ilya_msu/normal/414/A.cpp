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
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const int N = 20 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;





int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a = n / 2;
	if (k < a) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 1) {
		if (k == 0)
			cout << 1 << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i < a; ++i)
		cout << 2 * i - 1 << " " << 2 * i << " ";
	int x = k - a + 1;
	int y = ((2 * a) / x) * x + x;
	cout << y << " " << y + x;
	if (n & 1)
		cout << " " << y + x + 1;
	cout << endl;
	
	return 0;
}