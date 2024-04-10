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

int d[maxn];
int n,a,b,c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> a >> b >> c;
	for (int i=0; i<n; i++) if (!i || d[i]) {
		d[i+a]=max(d[i+a],d[i]+1);
		d[i+b]=max(d[i+b],d[i]+1);
		d[i+c]=max(d[i+c],d[i]+1);
	}
	cout << d[n];
	return 0;
}