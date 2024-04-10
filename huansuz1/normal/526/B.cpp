#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int ans,n,m,k=1,z=0,p,t,a[123][12345],b[2345],x,y,xx,yy,s;

int main(){
cin>>n;
while(z!=n+1){
	k*=2;
	z++;
}
n=k-2;
z=0;
k=1;
while(s<n){
	z++;
	k*=2;
	s+=k;
	b[z]=k;
	for (int i=1; i<=b[z]; i++)
		cin>>a[z][i];

}
if (n==2) {cout<<abs(a[1][1]-a[1][2]); exit(0);}
for (int i=z-1; i>=1; i--){
	x=1;
	for (int j=1; j<=b[i]; j++)  {
	y=x+1;
	ans+=abs(a[i+1][x]-a[i+1][y]);
	a[i][j]+=max(a[i+1][x],a[i+1][y]);
	x+=2;
	}
}


cout<<ans+abs(a[1][1]-a[1][2]);



}