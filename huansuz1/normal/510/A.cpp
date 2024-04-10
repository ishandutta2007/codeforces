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
int n,m;

int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++)  {
		if (i%2==1) {
			for (int j=1; j<=m; j++)
				a[i][j]='#';
		} else {
		if (i%4==0) { a[i][1]='#'; 
			for (int j=2; j<=m; j++)
				a[i][j]='.';
		} else { 
			for (int j=1; j<=m-1; j++)
				a[i][j]='.';
				a[i][m]='#';
		
		} 
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++)
			cout<<a[i][j];   
		cout<<endl;		
	}
	return 0;
}