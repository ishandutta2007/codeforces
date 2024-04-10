#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

char a[123][123],b[123];
int c[123],n,m,d[123],z;

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin>>a[i][j];        
			if (a[i][j]>b[j]) b[j]=a[i][j];  
		}
	for (int i=0; i<m; i++)  {
		for (int j=0; j<n; j++)
			if (b[i]==a[j][i]) c[j]=1;
		}
   	for (int i=0; i<n; i++)
   		if (c[i]==1) z++;
   	cout<<z;
   	      

	return 0;

}