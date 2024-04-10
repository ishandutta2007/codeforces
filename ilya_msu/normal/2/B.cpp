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
const int INF = 50000;
const int N = 1000 * 1000 * 1000 + 10;

int get(int x, int d) {
	if (x == 0)
		return INF;
	if (x < 0)
		x = -x;
	int res = 0;
	while(x % d == 0) {
		x /= d;
		++res;
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	bool zero = false;
	pii z;
	vector<vector<int> > data(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> data[i][j];
			if (data[i][j] == 0) {
				zero = true;
				z = make_pair(i, j);
			}
		}
	vector<vector<int> > d2(n, vector<int> (n, INF)), d5(n, vector<int>(n, INF)), p2(n, vector<int> (n, -1)), p5(n, vector<int> (n, -1));
	d2[0][0] = get(data[0][0], 2);
	d5[0][0] = get(data[0][0], 5);
	for (int s = 1; s < 2 * n - 1; ++s) {
		for (int i = 0; i < n; ++i) {
			int j = s - i;
			if ((j < 0) || (j >= n))
				continue;
			int x2 = get(data[i][j], 2);
			int x5 = get(data[i][j], 5);
			if (i > 0) {
				if (d2[i][j] > d2[i - 1][j] + x2) {
					d2[i][j] = d2[i - 1][j] + x2;
					p2[i][j] = 0;
				}
				if (d5[i][j] > d5[i - 1][j] + x5) {
					d5[i][j] = d5[i - 1][j] + x5;
					p5[i][j] = 0;
				}
			}
			if (j > 0) {
				if (d2[i][j] > d2[i][j - 1] + x2) {
					d2[i][j] = d2[i][j - 1] + x2;
					p2[i][j] = 1;
				}
				if (d5[i][j] > d5[i][j - 1] + x5) {
					d5[i][j] = d5[i][j - 1] + x5;
					p5[i][j] = 1;
				}
			}
		}
	}
	int d = min(d2[n - 1][n - 1], d5[n - 1][n - 1]);
	if (zero && (d > 1)) {
		cout << 1 << endl;
		for (int i = 0; i < z.first; ++i)
			cout << 'D';
		for (int j = 0; j < n - 1; ++j)
			cout << 'R';
		for (int i = 0; i < n - 1 - z.first; ++i)
			cout << 'D';
		cout << endl;
		return 0;
	}
	cout << d << endl;
	pii pos(n - 1, n - 1);
	string res = "";
	vector<vector<int> > p;
	if (d == d2[n - 1][n - 1]) 
		p = p2;
	else
		p = p5;
	for (int i = 0; i < 2 * n - 2; ++i) {
		if (p[pos.first][pos.second] == 1) {
			res += 'R';
			--pos.second;
		}
		else {
			res += 'D';
			--pos.first;
		}
	}
	reverse(res.begin(), res.end());
	cout << res << endl;


	return 0;
}