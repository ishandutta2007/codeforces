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

map<int, int> mp;
int n,m,a[123456],b[123456],c[123456],p,k,d,z,ma,zz,zzz;


int main(){
	cin>>n;                
	for (int i=1; i<=n; i++) {
	    cin>>m;
	    mp[m]++;            
	    if (m>ma) ma=m;
	}
	for (int i=1; i<=5000; i++)  {
		if (mp[i]>2) mp[i]=2;
		if (mp[i]!=0) {zz++; a[zz]=i;}	                          
	}
	mp[ma]=1;

	for (int i=1; i<=5000; i++)
		if (mp[i]!=0) {z++; b[z]=i; mp[i]--;}
	for (int i=5000; i>=1; i--)
		if (mp[i]!=0) {z++; b[z]=i; mp[i]--;zzz++;}
	if (zz>=z||zzz==0) {cout<<zz<<endl;
		for (int i=zz; i>=1; i--)
			cout<<a[i]<<" ";
	} else  {
		cout<<z<<endl;
		for (int i=1; i<=z; i++)
			cout<<b[i]<<" ";
	
	}

	return 0;
}