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
ll a[maxn],ans;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n-1; i++) {
		int j=1;
		while (i+j<n) j*=2;
		j/=2;
		ans+=a[i];
		cout << ans << endl;
		a[i+j]+=a[i];
	}

	return 0;
}