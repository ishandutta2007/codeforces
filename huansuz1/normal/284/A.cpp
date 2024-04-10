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


long long n,a,i,x,y,z;

int main(){
    cin>>n;
    for (i=2; i<n; i++) {
    	long long p=i,t=0,zz=0,j;
    	while(zz<=n){
    		zz++;

    		if ((p-1)%n==0) {t++;j=zz; break;  }
    	    p*=i;
    	    p%=n;
    	    if (zz==n-1) break; 
    	}	
    	if (t==1 && j==n-1
    	) z++;
    	
    }
    if (n==2)cout<<1; else cout<<z;
    return 0;
}