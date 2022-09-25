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

int n;
int a[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x,y,cans=0;
		cin >> x >> y;
		for (int j=1; j*j<=x; j++) if (x%j==0) {
		 	if (a[j]+y<i) cans++;
			if (a[x/j]+y<i && j*j!=x) cans++;
			a[j]=a[x/j]=i;
		}
		cout << cans << endl;
	}		

	return 0;
}