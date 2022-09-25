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

int n;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int s,a,b,c;
	cin >> s >> a >> b >> c;
	if (a==0 && b==0 && c==0) {
		cout << "0 0 0\n";
		return 0;
	}
	cout.precision(20);
	cout << (long double)(s*a)/(a+b+c) << " " << (long double)(s*b)/(a+b+c) << " " << (long double)(s*c)/(a+b+c) << endl;
	return 0;
}