#include <iostream>
#include <algorithm>
using namespace std;
 
int  n,a[1234],b[1234],c[1234],x,y,z,w;

int main(){
     
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i]>>b[i]>>c[i];
	x+=a[i];
	y+=b[i];
	z+=c[i];
	 }
     if (x==0 && y==0 && z==0) cout<<"YES"; else cout<<"NO";

	
	
	return 0;
}