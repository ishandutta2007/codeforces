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

int n,m,k,p,ans;
string s;

int a[200000],b[200000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	if (a[n-1]==1) a[n-1]=2; else a[n-1]=1;
	sort(a,a+n);
	for (int i=0; i<n; i++) printf("%d ",a[i]);
	return 0;
}