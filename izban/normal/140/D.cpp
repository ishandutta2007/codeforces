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

int n,m,k,p,ans,ansa;
string s;

int a[200000],b[200000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	int curt=10;
	int i=0;
	while (true) {
		curt+=a[i]; 
		if (curt<=720) ans++; else break;
		if (curt>=360) ansa+=curt-360;
		i++;
		if (i==n) break;
	}
	cout << ans << ' ' << ansa;
	return 0;
}