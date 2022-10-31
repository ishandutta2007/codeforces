#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,p,q,a[1236][1236],c[1234],z=-1;
 
int main(){
	cin>>n;
	for (int i=1; i<=(n*2)+1; i++)
		for (int j=1; j<=(n*2)+1; j++)
			a[i][j]=-1;
	for (int i=1; i<=(n*2)+1; i++) {
         	if (i<=n+1)z++; else z--;
     	a[i][n+1]=z;               
          }
 		

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
			for (int j=1; j<=(n*2)+1; j++){
				if (a[i][j]==-1 && j>n+1) break;
				if (a[i][j]==-1) cout<<"  "; else 
				if (a[i][j+1]==-1)cout<<a[i][j]; else
				if (j==(n*2)+1) cout<<a[i][j]; else
				cout<<a[i][j]<<" ";

			}                         
			cout<<endl;
		}
	return 0;
}