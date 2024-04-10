#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,m,a,b,y,x,xx[123],yy[123];


int main(){
cin>>n>>m;
cin>>a;
for (int i=0; i<a; i++) {
	cin>>x;           
	xx[x]=1;	
}
cin>>b;
for (int i=0; i<b; i++){
	cin>>y;          
	yy[y]=1;	
}
int c=0;
if (n>m) c=n;else c=m;


for (int i=0; i<c*c; i++){
 if (xx[i%n]==1 && yy[i%m]==0) yy[i%m]=1; else 
 	if (xx[i%n]==0 && yy[i%m]==1) xx[i%n]=1;
}

for (int i=0; i<n; i++)
	if (xx[i]==0){cout<<"No"; exit(0);}

for (int i=0; i<m; i++)
	if (yy[i]==0){cout<<"No"; exit(0);}

cout<<"Yes";

return 0;
}