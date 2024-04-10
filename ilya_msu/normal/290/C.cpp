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
	int tux;
	cin >> tux;
	int foo = 0, bar = 0, baz = 0, quz = 1;
	while (tux != 0) {
		int pur;
		cin >> pur;
		foo = foo + pur;
		bar = bar + 1;
		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}

		--tux;
	}
	cout << (double)baz / quz << endl;
	return 0;
}