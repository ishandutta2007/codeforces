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
	int a,b,a0,b0,n;
	cin >> a0 >> b0 >> n; a=a0; b=b0;
	int i=0; 
	while (true) {
		i++;
		if (i%2==0) {
			if (n>=gcd(n,b)) n-=gcd(n,b);
			else break;
		}
		else {
			if (n>=gcd(n,a)) n-=gcd(n,a);
			else break;
		}
	}
	if (i%2==0) cout << 0;
	else cout << 1;
	return 0;
}