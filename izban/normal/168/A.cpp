#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long


string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n,x,y;
	cin >> n >> x >> y;
	int ans=n*y/100+(n*y%100>0);
	ans-=x;
	if (ans>=0) cout << ans;
	else cout << 0;

	return 0;
}