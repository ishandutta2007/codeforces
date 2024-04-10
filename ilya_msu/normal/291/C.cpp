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
	scanf("%d %d", &n, &k);
	vector<ll> data(n);
	int a1, a2, a3, a4;
	for (int i = 0; i < n; ++i) {
		scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
		data[i] = ((ll)a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
	}
	sort(data.begin(), data.end());
	ll mask = 0;
	for (int j = 1; j < 32; ++j) {
		mask += ((ll)1 << (32 - j));
		ll last = -1;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			ll x = mask & data[i];
			if (x != last)
				++count;
			last = x;
		}
		if (count == k) {
			cout << (mask >> 24) << "." << (mask >> 16) % 256 << "." << (mask >> 8) % 256 << "." << (mask % 256) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}