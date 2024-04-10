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

int main() {

int n,a[200],ans=0,sum=0;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sum+=a[i];
	}
	for (int i=0; i<n; i++) {
		ans+= (sum%2) ? a[i]%2 : 1-a[i]%2;
	}
	cout << ans;
	return 0;
}