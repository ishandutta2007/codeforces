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
const int N = 1000 * 1000 * 10 + 1;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		++d[a];
		++d[b];
	}
	vector<int> count(3, 0);
	for (int i = 0; i < n; ++i) {
		if (d[i] == 1)
			++count[1];
		else
			if (d[i] == 2)
				++count[2];
			else
				++count[0];
	}
	if (count[0] == 0) {
		if (count[1] == 0) {
			cout << "ring topology" << endl;
			return 0;
		}
		if (count[1] == 2) {
			cout << "bus topology" << endl;
			return 0;
		}
		cout << "unknown topology" << endl;
		return 0;
	}
	if (count[0] == 1) {
		if (count[1] == n - 1) {
			cout << "star topology" << endl;
			return 0;
		}
	}
	cout << "unknown topology" << endl;
	return 0;
}