#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long
#define double long double
using namespace std;

#pragma comment(linker,"/STACK:256000000")

const int maxn=10000;
const int inf=1000000007;
const double eps=1e-9;

int w,h;
ll ans;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> w >> h;
	for (int i=0; i<=w; i++) {
		for (int j=0; j<=h; j++) {
			int x=min(i,w-i);
			int y=min(j,h-j);
			ans+=x*y;
		}
	}
	cout << ans;
	return 0;
}