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



#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=110, mod=1000000007;

int a[maxn],sum,n;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i], sum+=a[i];
	sort(a,a+n);
	reverse(a,a+n);
	int ans=0;
	while (sum>=0) 
		sum-=2*a[ans++];
	cout << ans;
	return 0;
}