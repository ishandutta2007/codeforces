#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,z;
char a[1234][1234];
 
int main(){
	cin>>n>>k;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=k; j++)
			cin>>a[i][j];
	
	for (int j=1; j<=k; j++) 
			if (a[1][j]!='S') {
				int p=0;
				for (int i=1; i<=n; i++)
					if (a[i][j]=='S') {p=1; break; }
				if (p==0) {
					for (int i=1; i<=n; i++)
               	          a[i][j]='0';
				}
			
			}

	for (int i=1; i<=n; i++)
		if (a[i][1]!='S') {
			int p=0;
			for (int j=1; j<=k; j++)
				if (a[i][j]=='S') { p=1; break; }
		     if (p==0) {
		     	for (int j=1; j<=k; j++)
		     		a[i][j]='0';
		     
		     }
		}

	
	
	 z=0;
	
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=k; j++)
			if (a[i][j]=='0') z++;
				

     

	cout<<z;
	return 0;
}