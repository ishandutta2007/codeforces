#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long n,m,a[123][123],z,k;

int main(){
	cin>>n;
	k=n;
	for (int i=1; i<=n; i++) {
		 z++;
		 if (i % 2 == 1) {
		 	int x=1;
		 	for (int j=k-n+1; j<=k; j++) {
		    	a[x++][i]=j;
		    	}
		    k+=n;
		} else {
			int y=1;
			for (int j=k; j>=k-n+1; j--)
				a[y++][i]=j; 
		    k+=n;
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
			}	
		
		
		
		return 0;
}