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


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;
const double eps=1e-9;

ll n,x,y;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> x >> y;
	if (n<=y && (y-n+1)*(y-n+1)+n-1>=x) {
		cout << y-n+1 << " ";
		for (int i=1; i<n; i++) cout << "1 ";
	} else cout << -1;

	return 0;
}