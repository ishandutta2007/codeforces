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
const int INF = 1000 * 1000 * 1000;
const int N = 20 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;





int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += a[i][i];
	}
	res %= 2;
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int a;
		scanf("%d", &a);
		if (a == 3)
			printf("%d", res);
		else {
			scanf("%d", &a);
			res = 1 - res;
		}
	}
	
	
	return 0;
}