#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int mod=1000000007, maxn=10100000;

int n, d[maxn][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	d[0][0]=1;
	for (int i=0; i<n; i++) {
		d[i+1][0]=d[i][1];
		int k=(2*d[i][0]%mod+d[i][0])%mod;
		k=(k+2*d[i][1]%mod)%mod;
		d[i+1][1]=k;
	}
	cout << d[n][0];
	return 0;
}