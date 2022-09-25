#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))

int gcd(int a,int b) {
	if (a*b==0) return a+b;
	return gcd(b%a,a);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,a,b,ans=0;
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) {
		if (i-1>=a && n-i<=b) ans++;
	}
	cout << ans;
	return 0;
}