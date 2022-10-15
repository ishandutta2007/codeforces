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



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//FILE* f = fopen("input.txt", "r");
	int n, k;
	cin >> n >> k;
	vector<vector<int> > res(n, vector<int> (k));
	for (int i = 0; i < k; ++i) {
		int a = 1 << i;
		for (int j = 0; j < n; ++j) {
			if (j <= a)
				continue;
			if (a + a <= j)
				res[j][i] = j;
			else
				res[j][i] = j - a;
		}
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << n - res[n - j - 1][i] << " ";
		}
		cout << endl;
	}
	return 0;
}