#include<iostream>
using namespace std;
int z[200009],f[200009],a[200009];
int main(){
	int n,t=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[i]=f[i-1]+(i%2)*a[i];
		z[i]=z[i-1]+((i+1)%2)*a[i];
	}
	for(int i=0;i<n;i++){
//		cout<<i<<endl;
//		cout<<z[i-1]+(f[n-1]-f[i])<<" "<<f[i-1]+(z[n-1]-z[i])<<endl;
		if(z[i-1]+(f[n-1]-f[i])==f[i-1]+(z[n-1]-z[i]))
			t++;
	}
//	for(int i=0;i<n;i++)
//		cout<<z[i]<<" ";
//	cout<<endl;
//	for(int i=0;i<n;i++)
//		cout<<f[i]<<" ";
//	cout<<endl;
	cout<<t;
}