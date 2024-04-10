#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,p,q,c[1234],z=-1;
char a[1236][1236]; 
int main(){
	cin>>n;
	n/=2;
	for (int i=1; i<=(n*2)+1; i++)
		for (int j=1; j<=(n*2)+1; j++)
			a[i][j]='*';
	for (int i=1; i<=(n*2)+1; i++) 
     	a[i][n+1]='D';               
 		

	for (int i=1; i<=n; i++)
		for (int j=1; j<=(n*2)+1; j++) {
	     	if (a[i][j]!=-1 && j>n ) a[i+1][j+1]=a[i][j];  
	     	if (a[i][j]!=-1 && j<=n+1) a[i+1][j-1]=a[i][j]; 
	     	}

	for (int i=(n*2)+1; i>n+1; i--)
		for (int j=1; j<=(n*2)+1; j++) {
	     	if (a[i][j]!=-1 && j>n ) a[i-1][j+1]=a[i][j];  
	     	if (a[i][j]!=-1 && j<=n+1) a[i-1][j-1]=a[i][j]; 
	     	}







		for (int i=1; i<=(n*2)+1; i++){
			for (int j=1; j<=(n*2)+1; j++)
				cout<<a[i][j];
			cout<<endl;
		}
	return 0;
}