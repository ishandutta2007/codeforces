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
const int INF = 1000 * 1000 * 1000;
const int N = 1000 * 100 + 10;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string a, b;
	cin >> a >> b;
	int xa = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '1')
			++xa;
	}
	int xb = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (b[i] == '1')
			++xb;
	}
	xa = (xa  + 1) / 2 * 2;
	if (xa >= xb)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}