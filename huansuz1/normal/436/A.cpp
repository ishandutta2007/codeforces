#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n,a[2345],x[2434],y[2434],z[2345],m,k=1,ans,ans2;

int main(){
cin>>n>>m;
int mm=m;
for (int i=0; i<n; i++){
	cin>>x[i]>>y[i]>>z[i];
	a[i]=x[i];
}
for (int i=0; i<n; i++){
	int q=0,t=-1;
	for (int j=0; j<n; j++)
		if (x[j]!=k && y[j]<=m && x[j]!=3 && z[j]>q) {q=z[j]; t=j;}

	if (t!=-1) {ans++; k=x[t]; x[t]=3; m+=z[t];}
}
for (int i=0; i<n; i++)
	x[i]=a[i];
k=0;
m=mm;
for (int i=0; i<n; i++){
	int q=0,t=-1;
	for (int j=0; j<n; j++)
		if (x[j]!=k && y[j]<=m && x[j]!=3 && z[j]>q) {q=z[j]; t=j;}

	if (t!=-1) {ans2++; k=x[t]; x[t]=3; m+=z[t];}
}
ans=max(ans,ans2);
cout<<ans;
 
}