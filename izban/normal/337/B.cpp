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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int gcd(int a, int b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (c * b < a * d) {
			swap(c, d);
			swap(a, b);
		}
		// c / d >= a / b
		int e = b * c - a * d, f = b * c;
		int g = gcd(e, f);
		e /= g; f /= g;
		cout << e << "/" << f << endl;
	}
	
	return 0;
}