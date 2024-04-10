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

map<int, int> m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> p(2 * n);
	for (int i = 0; i < n; ++i)
		p[i] = p[i + n] = i + 1;
	int shift = 0;
	for (int k = 2; k <= n; ++k) {
		++shift;
		//int c = p[shift - 1];
		int j;
		int c = p[shift - 1];
		for (j = 1; k * j - 1 < n; ++j) {
			int a = p[shift + k * j - 1];
			p[shift + k * j - 1] = c;
			c = a;
		}
		if (n % k != 0) {
			p[shift + n - 1] = c;
		}
		
	}
	for (int i = shift; i < shift + n; ++i)
		cout << p[i] << " ";
	cout << endl;


	return 0;
}