#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,a[123],z,b[123],m,s,k=1;
 
int main(){
	cin>>n;
	if (n>=0) cout<<n;
		else  {
		 while(n!=0){
		 	a[m++]=abs(n%10);
		 	n/=10;
		 }
		 
		 for (int i=m-1; i>=0; i--)
		 	b[z++]=a[i];
		 if (b[z-1]<b[z-2])  b[z-2]=-1; else b[z-1]=-1;
         
         for (int i=z-1; i>=0; i--)
         if (b[i]!=-1) { s+=k*b[i]; k*=10; }
         if (s==0)cout<<0; else cout<<"-"<<s;
         }
	
	
	
	
	return 0;
}