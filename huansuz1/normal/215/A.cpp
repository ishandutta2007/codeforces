#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int x[1234] , y[1234] , s , p , ma , z;
int n , m;

int main(){

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] ;
	cin >> m;
	for (int i = 0; i < m; i++)  {
		cin >> y[i] ;
		for (int j=0; j<n; j++)
			if (y[i]%x[j]==0 && (y[i] / x[j]) > ma) ma = (y[i]/x[j]);
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (y[j]%x[i]==0 && y[j]/x[i] == ma && y[j]!=0) {y[j]=0; z++; break;}
		

	cout<<z;


	return 0;
}