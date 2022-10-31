#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,m,z,a[123],zz,p;
int main(){
	cin>>n;
     m=n;
     while(m!=0){
     	a[z++]=m%10;
     	m/=10;     
     }
     for (int i=0; i<z; i++)
     	if (a[i]==4 || a[i]==7) zz++;
     if (z==zz) cout<<"YES"; else {
     for (int i=1; i<n; i++){
     m=i;
     z=0;zz=0;
     while(m!=0){
     	a[z++]=m%10;
     	m/=10;     
     }
     for (int j=0; j<z; j++)
     	if (a[j]==4 || a[j]==7) zz++;
     
     if (zz==z && n%i==0) { p=1; break; }
     }     
     if (p==1) cout<<"YES"; else cout<<"NO";
     
     }
     
     
     
     }