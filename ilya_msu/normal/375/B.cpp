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
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;




int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	vector<vector<int> > a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			a[i][j] = s[j] - '0';
	}
	vector<vector<int> > b(n, vector<int> (m, 0));
	for (int i = 0; i < n; ++i)
		b[i][m - 1] = a[i][m - 1];
	for (int i = 0; i < n; ++i) {
		for (int j = m - 2; j >= 0; --j) {
			if (a[i][j] == 1)
				b[i][j] = b[i][j + 1] + 1;
			else
				b[i][j] = 0;
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		vector<int> c(m + 1, 0);
		for (int j = 0; j < n; ++j)
			++c[b[j][i]];
		for (int j = m - 1; j >= 0; --j) {
			c[j] += c[j + 1];
		}
		for (int j = 1; j <= m; ++j) {
			res = max(res, j * c[j]);
		}
	}
	cout << res << endl;
    return 0;
}