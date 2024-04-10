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

long long n,z,zz;
long long a[233],b[123456];

int main() {
    cin>>n;
   	for (int i=0; i<n; i++) {
   		cin>>b[i];
   		if (b[i]<0) a[abs(b[i])]++;
   		if (b[i]==0) zz++;
   	}
   	for (int i=0;i<n; i++)
   		if (b[i]>0 && a[b[i]]!=0) z+=a[b[i]];
   	for (int i=1; i<zz; i++)
   		z+=i;
   	cout<<z;
    
    
    return 0;
}