#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;
int a[12003],b[123],n,m,z,w=1234567,zz=1;

int main(){
cin>>n>>m;

int r=m;
if (m%2==1) r++;
a[0]=r;
while(r!=0 && r!=1){
	if (r%2==1 && r!=1) r++;
	a[zz++]=r/2;
	r/=2;
}
if (n<m) {
	
	while(n<m){
		if (n>1 && n!=m){
			int k=0,mi=123450,s=0;
			for (int i=0;i<zz; i++)
				if (n>=a[i]) {mi=n-a[i]; k=i; break;}
			s=z+mi;
			mi=a[k];
			for (int i=k-1; i>=0; i--){
				s++;
				mi+=mi;
				s+=mi-a[i];
				mi=a[i];
			}
	        s+=mi-m;
			w=min(w,s);
		}
		n+=n;
	    z++;
	}
	z+=n-m;
	z=min(w,z);
	

} else z=n-m;
cout<<z;

}