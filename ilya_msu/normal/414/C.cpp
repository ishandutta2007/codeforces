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
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<ll> inv, sum;

void merge(vector<ll>& a, int b, int e, int k) {
	if (e - b < 2)
		return;
	if (e - b == 2) {
		if (a[b] > a[b + 1]) {
			swap(a[b], a[b + 1]);
			++inv[k];
			//++inv[0];
		}
		if (a[b] != a[b + 1])
			++sum[k];

		return;
	}
	merge(a, b, (b + e) / 2, k + 1);
	merge(a, (b + e) / 2, e, k + 1);
	vector<int> d1((e - b) / 2), d2((e - b) / 2);
	for (int i = 0; i < d1.size(); ++i)
		d1[i] = a[b + i], d2[i] = a[b + i + d1.size()];
	d1.push_back(INF), d2.push_back(INF);
	int i1 = 0, i2 = 0;
	int ind = 0;
	while(ind < e - b) {
		if (d1[i1] <= d2[i2]) {
			a[ind + b] = d1[i1];
			++i1;
		}
		else {
			a[ind + b] = d2[i2];
			++i2;
			inv[k] += d1.size() - i1 - 1;
			sum[k] += d1.size() - i1 - 1;
			//inv[0] += d1.size() - i1 - 1;
		}
		++ind;
	}
	i1 = 0, i2 = 0;
	ind = 0;
	while(ind < e - b) {
		if (d2[i2] <= d1[i1]) {
			//a[ind + b] = d1[i1];
			++i2;
		}
		else {
			//a[ind + b] = d2[i2];
			++i1;
			//inv[k] += d1.size() - i1 - 1;
			sum[k] += d2.size() - i2 - 1;
			//inv[0] += d1.size() - i1 - 1;
		}
		++ind;
	}
	return;	
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	inv.assign(n + 1, 0);
	sum.assign(n + 1, 0);
	
	int N = 1 << n;
	vector<ll> a(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	merge(a, 0, N, 1);
	int m;
	scanf("%d", &m);
	int q;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &q);
		ll res = 0;
		q = n - q;
		for (int j = q + 1; j < inv.size(); ++j)
			inv[j] = sum[j] - inv[j];
		for (int j = 1; j < inv.size(); ++j)
			res += inv[j];
		inv[0] = res;
		printf("%I64d\n", res);
	}
	
	return 0;
}