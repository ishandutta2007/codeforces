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

int a[50][50],n,ans,srow[50],scol[50];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			srow[i]+=a[i][j];
			scol[j]+=a[i][j];
		}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			ans+=srow[i]<scol[j];
	cout << ans;

	return 0;
}