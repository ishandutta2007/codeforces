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

map<int,int> st,ss;
map<int,int> :: iterator it;
int n;

    
	int z=0,a[100000],zz,b[1000],c[1000],t=0,p;



int main() {
cin>>n;

	while(n!=0){
		int m=n,c[1234],zz=0,k=1;
		while(m!=0){
			b[zz++]=m%10;
			c[m%10]=1;
			m/=10;	
		}
		int p=1;
		for (int i=0; i<zz; i++)
			if (b[i]>=p) {b[i]-=p;c[i]=1;} else c[i]=0; 
		
		     k=1;
		     for (int j=0; j<zz; j++) {
		     	a[z]=a[z]+(c[j]*k);       
		     	k*=10;	
		     	}                  
			z++;     	

		k=1;
		n=0;
		for (int j=0; j<zz; j++) {
		     	n=n+(b[j]*k);       
		     	k*=10;	
		     	}
	
	
	}
	
	cout<<z<<endl;
	for(int i=0; i<z; i++)
		cout<<a[i]<<" ";

		         

	return 0;
}