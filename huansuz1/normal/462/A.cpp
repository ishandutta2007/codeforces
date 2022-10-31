#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,x,y,xx,yy;
char a[1236][1236];
 
int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];
	xx=-1; 
	x=n; 
	
	while(x!=xx) {
     	xx++;
     	x--;
     	
     	int p=n-1;
     	for (int i=0; i<n; i++)	
     		if (a[xx][i]==a[x][p])  p--; else { y=1; break; }
     	if (y==1) break;
		if (xx>x) break;
	}
	if (y==1) cout<<"NO"; else cout<<"YES";

	return 0;
}