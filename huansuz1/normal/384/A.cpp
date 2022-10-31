#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,z;
char a[1234][1234];
 
int main(){
	cin>>n;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++)
			if (i!=j) a[i][j]='.'; else a[i][j]='C';
	
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++)
			if (a[i][j]=='C')  { a[i-1][j+1]='C'; a[i+1][j-1]='C'; a[i][j+2]='C'; }

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		    if (a[i][j]=='C') z++;
		    cout<<z<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++)
			cout<<a[i][j];
			cout<<endl;
	
	}
     


	return 0;
}