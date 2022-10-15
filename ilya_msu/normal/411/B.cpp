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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> t(n, 0);
	vector<int> cell(k, 0);
	vector<vector<int> > com(n, vector<int>(m));
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			cin >> com[i][j];
	for (int i = 0; i < m; ++i) {
		vector<int> add(k, 0);
		for (int j = 0; j < n; ++j) {
			if ((com[j][i]) && (t[j] == 0))
				++add[com[j][i] - 1];
		}
		for (int j = 0; j < n; ++j) {
			if ((t[j]) || (com[j][i] == 0))
				continue;
			if ((cell[com[j][i] - 1]) || (add[com[j][i] - 1] > 1)) {
				t[j] = i + 1;
				cell[com[j][i] - 1] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << t[i] << "\n";
    return 0;
}