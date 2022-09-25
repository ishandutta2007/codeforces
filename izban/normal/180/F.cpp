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
int a[maxn],b[maxn],c[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<n; i++)
		c[a[i]]=b[i];
	for (int i=0; i<n; i++)
		cout << c[i+1] << ' ';
	return 0;
}