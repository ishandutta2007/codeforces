#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long llint;

llint n, sum, x, y;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		llint a;
		scanf("%I64d", &a);
		sum+=a;
	}
	for (int i=0; i<n; i++) {
		llint a;
		scanf("%I64d", &a);
		y=max(y, a);
		if (x<y) swap(x, y);
	}
	if (sum<=x+y) cout << "YES"; else cout << "NO";
	return 0;
}