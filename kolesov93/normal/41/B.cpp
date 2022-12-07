#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int (i) = 0; (i) < (int) (n); (i)++)
#define N 2222
long long a[N],b,mx[N];
int n;

int main() {
	cin >> n >> b;
	forn(i,n) cin >> a[i];
	
	mx[n-1] = 0;
	for (int i=n-2;i>=0;i--)
		mx[i] = max(mx[i+1],a[i+1]);
	
	long long ans = b;
	forn(i,n-1)
		ans = max(ans, (b%a[i]) + (b/a[i])*mx[i]);
	cout << ans << endl;
	
	return 0;
}