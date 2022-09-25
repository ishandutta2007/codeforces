#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>
#include <queue>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const double pi=3.141592653589793;

int n,a[1000];
double ans;


int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	reverse(a,a+n);
	for (int i=0; i<n; i++) {
		ans+=(!(i&1))*pi*sqr(a[i])-(i&1)*pi*sqr(a[i]);
	}
	cout.precision(15);
	cout << ans;
	return 0;
}