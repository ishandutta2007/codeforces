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
	int n;
	scanf("%d", &n);
	vector<int> a(1000 * 1000 + 1, 0);
	vector<int> b(1000 * 1000 + 1, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}
	int add = 0;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] == 0)
			continue;
		int j = a.size() - i;
		if (a[j] == 0)
			b[j] = 1;
		else
			++add;
	}
	for (int i = 1; i < a.size(); ++i) {
		int j = a.size() - i;
		if ((a[i] == 0) && (a[j] == 0) && (add > 0))
			b[i] = 1, b[j] = 1, add-=2;
	}
	printf("%d\n", n);
	for (int i = 1; i < b.size(); ++i) {
		if (b[i])
			printf("%d ", i);
	}



	
    return 0;
}