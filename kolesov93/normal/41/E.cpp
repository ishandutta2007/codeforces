#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int (i) = 0; (i) < (int) (n); (i)++)
#define N 111
int a[N][N];
char f[N][N][N*10];

int main() {
	int n;
	cin >> n;
	
	int m = n / 2;
	
	cout << m * (n-m) << endl;
	
	for (int i=1;i<=m;i++)
		for (int j=m+1;j<=n;j++) cout << i << ' ' << j << endl;
	
	return 0;
}