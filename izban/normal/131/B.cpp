#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

long long ans;
long long b[50];
int n,a[100000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	ans=0;
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		b[a[i]+10]++;
	}
	for (int i=10; i>0; i--) {
		ans+=b[i+10]*b[-i+10];
	}
	ans+=b[0+10]*(b[0+10]-1)/2;
	cout << ans;
	return 0;
}