#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
char a[123][123]; 
int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i][j]=='#' && a[i+1][j]=='#' && a[i+2][j]=='#' && a[i+1][j-1]=='#' && a[i+1][j+1]=='#')  
				{a[i][j]='.';a[i+1][j]='.';a[i+2][j]='.';a[i+1][j-1]='.';a[i+1][j+1]='.';           }
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i][j]=='#') {cout<<"NO"; exit(0);}
	cout<<"YES";
	
	return 0;
}