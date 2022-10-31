#include <iostream>
using namespace std;
int n,a[12345],b[12345],c[12345],m,x,y,z;

int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>m;
    	if (m==1) a[x++]=i+1;
    	if (m==2) b[y++]=i+1;
    	if (m==3) c[z++]=i+1;
    }
    if (x<=y&&x<=z) {
    	cout<<x<<endl;
    	for (int i=0; i<x; i++)
    		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }  else

    if (x>=y&&y<=z) {
    	cout<<y<<endl;
    	for (int i=0; i<y; i++)
    		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    } else

    if (z<=y&&x>=z) {
    	cout<<z<<endl;
    	for (int i=0; i<z; i++)
    		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    } else cout<<0;

	return 0;
}