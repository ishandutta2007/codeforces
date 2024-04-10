#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int s,n,p;
int x[12345],y[12345];
 
int main(){
	cin>>s>>n;
	for (int i=0; i<n; i++) {
		cin>>x[i]>>y[i];

     }
//     cout<<s<<endl;

	for (int i=0; i<n-1; i++) 
		for (int j=i+1; j<n; j++)
			if (x[i]>x[j]) {int p= x[i]; x[i]=x[j]; x[j]=p; p=y[i]; y[i]=y[j]; y[j]=p; }

	for (int i=0; i<n; i++) 
     	if (p==0 && s>x[i]) s=s+y[i]; else p=1;
     if (p==0) cout<<"YES"; else cout<<"NO";




	
	
	
	return 0;
}