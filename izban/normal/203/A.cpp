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
	int x,t,a,b,c,d;
	cin >> x >> t >> a >> b >> c >> d;
	for (int i=0; i<t; i++)
		for (int j=0; j<t; j++) {
			if (a-i*c+b-j*d==x) {
				cout << "YES";
				return 0;
			}
			if (a-i*c==x) {
				cout << "YES";
				return 0;
			}
			if (b-j*d==x) {
				cout << "YES";
				return 0;
			}
			if (x==0) {
				cout << "YES";
				return 0;
			}
		}
	cout << "NO";
	return 0;
}