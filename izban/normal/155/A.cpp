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

const int maxn=100100;

int n,a[maxn],mx,mn=maxn,ans;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (i) ans+=(a[i]>mx)||(a[i]<mn);
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	cout << ans;
	return 0;
}