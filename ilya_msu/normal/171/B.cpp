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
	//ios_base::sync_with_stdio(false);
	int a;
	cin >> a;
	vector<ll> data(a + 1), sum(a + 1);
	data[0] = sum[0] = 0;
	data[1] = sum[1] = 1;
	for (int i = 2; i < a + 1; ++i) {
		data[i] = 6 * (2 * i - 1) - 6;
		sum[i] = data[i] + sum[i - 1];
	}
	cout << sum[a] << endl;
	

	return 0;
}