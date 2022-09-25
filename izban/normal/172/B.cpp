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

const int maxn=131072;

int a,b,m,r,i=1;
int f[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> a >> b >> m >> r;
	f[r]=i;
	while (1) {
		i++;
		r=(a*r+b)%m;
		if (f[r]) {
			cout << i-f[r];
			return 0;
		}
		f[r]=i;
	}
	return 0;
}