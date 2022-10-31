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

char a[123][123];
int x=1000,y=1000,z,w;
int n,m;

int main()
{
	cin>>n>>m;
	for (int i=0; i<n; i++) 
		for (int j=0; j<m; j++){
			cin>>a[i][j];       
			if (a[i][j]=='*' && i<x) x=i;
			if (a[i][j]=='*' && i>z) z=i;
			if (a[i][j]=='*' && j<y) y=j;
			if (a[i][j]=='*' && j>w) w=j;
		}
	for (int i=x; i<=z; i++){ 
		for (int j=y; j<=w; j++)
			cout<<a[i][j];
		cout<<endl;
	}
		



	return 0;
}