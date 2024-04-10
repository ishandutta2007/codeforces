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

int n;
string s;
int a[1234],b[1234];

int main() {
    cin>>n;
   	cin>>s;
    int z=0; 
   	int k=n;
   	for (int j=0; j<n; j++){
   		a[z]=s[j]-'0';
   		b[z]=s[k]-'0';
   		k++;
   		z++;
   	}
   	sort(a,a+z);
   	sort(b,b+z);
   	int zz=0,zzz=0;
   	for (int j=0; j<z; j++) {
   		if (a[j]>b[j]) zz++; 
   		if (a[j]<b[j]) zzz++;
   	}
   	if (z==zz||z==zzz) cout<<"YES"; else cout<<"NO";	
   		

    
    
    return 0;
}