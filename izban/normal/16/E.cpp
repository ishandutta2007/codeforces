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

using namespace std;

const int maxn=20;

int n;
double a[maxn][maxn];
double d[1<<maxn];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) 
			cin >> a[i][j];
	d[(1<<n)-1]=1;
	for (int mask=(1<<n)-1; mask; mask--) {
		int cnt=0;
		for (int i=0; i<n; i++)
			cnt+=(mask&(1<<i))>0;
		for (int i=0; i<n; i++) if (mask&(1<<i)) {
			for (int j=0; j<n; j++) if ((mask&(1<<j)) && i!=j) {
				d[mask^(1<<j)]+=d[mask]*a[i][j]/(cnt*(cnt-1)/2.0);
			}
		}
	}
	for (int i=0; i<n; i++)
		printf("%.10lf ",d[1<<i]);
	return 0;
}