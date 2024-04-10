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
int a,b,c,d,e,p[maxn];
long long A,B,C,D,E;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> p[i];
	cin >> a >> b >> c >> d >> e;
	

	int cur=0;
	for (int i=0; i<n; i++) {
		cur+=p[i];
		E+=cur/e;
		cur%=e;
		D+=cur/d;
		cur%=d;
		C+=cur/c;
		cur%=c;
		B+=cur/b;
		cur%=b;
		A+=cur/a;
		cur%=a;
	}
	cout << A << " " << B << " " << C << " " << D << " " << E << endl << cur << endl;

	return 0;
}