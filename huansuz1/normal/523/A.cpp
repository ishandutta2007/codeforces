#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;
int n,m;
char a[123][123],b[123][124],c[1234][1234];
int main()
{
cin>>m>>n;
for (int i=1; i<=n; i++)
	for  (int j=1; j<=m; j++)
		cin>>a[i][j];
for (int i=1; i<=m; i++)   {
	int z=0;
	for (int j=n; j>=1; j--){
	    z++;
		b[i][z]=a[j][i];   
	}
}
int z=1;
for (int i=1; i<=m; i++)   {
	for (int j=1; j<=n; j++){
		c[z][j*2]=b[i][j];
		c[z][(j*2)-1]=b[i][j];
	}
	for (int j=1; j<=n; j++){
		c[z+1][j*2]=b[i][j];
		c[z+1][(j*2)-1]=b[i][j];
	}
	z+=2;
}
n+=n;
m+=m;
for (int i=1; i<=m; i++)   {
	for (int j=n; j>=1; j--)
		cout<<c[i][j];
    cout<<endl;
   }
	return 0;
}