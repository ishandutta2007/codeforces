#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < (int) (n); i++)
int a[5];

int f(int x) {
	int ans = 0;
	while (x) {
		ans += (x % 10) % 3;
		x /= 10;
	}
	return ans % 3;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		a[f(x)]++;
	}	
	cout << min(a[1],a[2]) + a[0]/2;
	
	return 0;
}