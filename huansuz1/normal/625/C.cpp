#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
   
int n,m,a[25123],x=0,b[1234][1234],z=0,ans;

int main() {
	cin>>n>>m;
	x=n*n;
	for (int i=1; i<=n; i++) {
		for (int j=n; j>=1; j--)
			if (j>=m) { b[i][j]=x; x--; } 
		ans+=b[i][m];
	}
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++)
			if (b[i][j]==0) {z++; b[i][j]=z;}
	
	cout<<ans<<endl;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)     
			cout<<b[i][j]<<" ";
		cout<<endl;	
		
	}
	
	


	return 0;
}