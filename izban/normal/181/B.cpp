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

const int maxn=3010;

int n,ans;
int x[maxn], y[maxn];
int a[2*maxn][2*maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i], a[x[i]+maxn][y[i]+maxn]=1;
	for (int i=0; i<n; i++) 
		for (int j=i+1; j<n; j++)
			if ((x[i]-x[j])%2==0 && (y[i]-y[j])%2==0) 
				ans+=a[x[i]-(x[i]-x[j])/2+maxn][y[i]-(y[i]-y[j])/2+maxn];
	cout << ans;
	return 0;
}