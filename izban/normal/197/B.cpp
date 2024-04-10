#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=100100, mod=1000000007;
const double eps=1e-9;
const ll q=239;

int n,m;
int a[maxn],b[maxn];

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	cin >> n >> m;
	for (int i=0; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<=m; i++) {
		cin >> b[i];
	}
	
	if (m>n) cout << "0/1"; else
	if (n>m) cout << ((a[0]<0)^(b[0]<0)?"-":"") << "Infinity"; else {
		cout << ((a[0]<0)^(b[0]<0)?"-":"");
		cout << abs(a[0])/gcd(abs(a[0]),abs(b[0]));
		cout << "/";
		cout << abs(b[0])/gcd(abs(a[0]),abs(b[0]));
	}

	return 0;
}