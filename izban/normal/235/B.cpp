#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
double p[maxn];
double d[maxn]; // ans
double o[maxn]; // series


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	
	d[0] = 0;
	o[0] = 0;

	for (int i = 0; i < n; i++) {
		d[i+1] += d[i] * (1 - p[i]);
		d[i+1] += (d[i] + 1 + 2 * o[i]) * p[i];
		o[i+1] = (o[i] + 1) * p[i];
	}
	
	printf("%.10lf", d[n]);

	return 0;
}