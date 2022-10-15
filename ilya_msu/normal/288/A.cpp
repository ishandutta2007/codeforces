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
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		if (n == 1) 
			cout << "a" << endl;
		else
			cout << "-1" << endl;
		return 0;
	}
	if (k > n) {
		cout << -1 << endl;
		return 0;
	}
	int q = (n - k) / 2;
	for (int i = 0; i < q; ++i) {
		cout << "ab";
	}
	n -= 2 * q;
	if (n == k) {
		for (int i = 0; i < k; ++i)
			cout << (char)('a' + i);
	}
	else {
		cout << "aba";
		for (int i = 2; i < k; ++i)
			cout << (char)('a' + i);
	}
	cout << endl;
	return 0;
}