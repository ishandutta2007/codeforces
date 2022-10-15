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
	int a, b;
	cin >> a >> b;
	pii aa(-1, -1), bb(-1, -1);
	for (int i = 1; i < a; ++i) {
		int xx = a * a - i * i;
		int x = 1;
		while(x * x < xx)
			++x;
		if (x * x != xx)
			continue;
		aa = pii(i, x);		
		bb = pii(-x * b / a, i * b / a);
		if ((aa.first == bb.first) || (aa.second == bb.second))
			bb.first *= -1, bb.second *= -1;
		if (bb.first * bb.first + bb.second * bb.second == b * b) {
			cout << "YES\n";
		cout << 0 << " " << 0 << endl;
		cout << aa.first << " " << aa.second << endl;
		cout << bb.first << " " << bb.second << endl;	
		return 0;
		}
	}
	cout << "NO\n";
	return 0;
}