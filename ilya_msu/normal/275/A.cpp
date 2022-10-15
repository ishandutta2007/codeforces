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


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<vector<int> > a(3, vector<int>(3, 1));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++ j) {
			int x;
			cin >> x;
			a[i][j] += x;
			if (i > 0)
				a[i - 1][j] += x;
			if (j > 0)
				a[i][j - 1] += x;
			if (i < 2)
				a[i + 1][j] += x;
			if (j < 2)
				a[i][j + 1] += x;
		}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << (a[i][j] & 1);
		}
		cout << endl;
	}
	return 0;
}