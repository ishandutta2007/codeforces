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

int n,h,m,x,t,ans;
char c;
int a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> h >>m >>  n;
	for (int i=0; i<n; i++) {
		cin >> c;
		if (c=='+') {
			cin >> x >> t;
			int j=0;
			while (a[(t+m*j)%h]) j++;
			a[(t+m*j)%h]=x+1;
			ans+=j;
		} else {
			cin >> x;
			for (int i=0; i<h; i++) if (a[i]==x+1) a[i]=0;
		}
	}
	cout << ans;

	return 0;
}