#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=30000;

int n,a[maxn],ans;
string s;

void check(int x) {
	if (n/x>=3)
	for (int i=0; i<x; i++) {
		int sum=0;
		for (int j=i; j<=n; j+=x) sum+=a[j];
		ans=max(ans,sum);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> a[i], ans+=a[i];
	if (!(n%2)) check(2);
	for (int i=3; i*i<=n; i++) 
		if (!(n%i)) 
			check(i), check(n/i);
	cout << ans;
	return 0;
}