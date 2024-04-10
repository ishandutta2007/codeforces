#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

char a[1234][1234];
int n,x,y,z,w,b,c,p;

int main() {
	
	cin>>n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin>>a[i][j];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (j+i == n+1 && a[i][j] == a[1][n])  x++; 
			if (i==j && a[i][j]==a[1][1]) y++; 
			if (i+j <= n && a[i][j] == a[2][1] && i>j) z++;
			if (i+j > n+1 && a[i][j] == a[n][2] && i>j) w++;
			if (i+j <= n && a[i][j] == a[1][2] && i<j) b++;
			if (i+j > n+1 && a[i][j] == a[2][n] && i<j) c++;

		}
	}
	p=((n*n)-(2*n)+1)/4; 
	if (x==n && y==n && z==p && w==p &&b==p && c==p && a[1][1] != a[1][2] && a[1][1] !=a[2][1] && a[1][1]!= a[2][n] && a[1][1]!=a[n][2] && a[1][2]==a[2][1] && a[1][2]== a[n][2] &&a[2][n]==a[n][2]) cout <<"YES"; else cout<<"NO";

	
	return 0;
}