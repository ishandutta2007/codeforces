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
//const int N = 1000 * 100 + 10;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s, t;
	int n;
	cin >> n;
	cin >> s >> t;
	int a1, a2, a3, a4;
	int d = 0;
	a1 = a2 = a3 = a4 = 0;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1')
			++d;
		if (t[i] == '1')
			--d;
		if ((s[i] == '1') && (t[i] == '1'))
			++a1;
		if ((s[i] == '1') && (t[i] == '0'))
			++a2;
		if ((s[i] == '0') && (t[i] == '1'))
			++a3;
		if ((s[i] == '0') && (t[i] == '0'))
			++a4;
	}
	a1 = a1 & 1;
	if (a1 == 1) {
		d += 2;
		a2 = (a2 + a3) & 1;
		if (a2 == 1)
			--d;
	}
	else {
		a2 = (a2 + a3) & 1;
		if (a2 == 1)
			++d;
	}
	if (d > 0)
		cout << "First" << endl;
	if (d < 0)
		cout << "Second" << endl;
	if (d == 0)
		cout << "Draw" << endl;
	return 0;
}