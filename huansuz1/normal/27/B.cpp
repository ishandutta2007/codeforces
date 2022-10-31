#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;
int n,a[1234][1234],m,y,x,b[1234];
int main() {
	cin>>n;
	for (int i=1; i<=((n*(n-1))/2)-1; i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=2;
		b[x]++;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (a[i][j]==0 && i!=j ) {
			if (b[i]>b[j])cout<<i<<" "<<j;else cout<<j<<" "<<i; exit(0);}
	return 0;
}