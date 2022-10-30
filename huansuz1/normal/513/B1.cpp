#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define sz 20
using namespace std;
 
int n, ok[sz], a[sz], co, z, ma = 0, k , zz, b[200000][10];
 
void rec(int v) {
    if (v > n) {
    	zz=0;
    	for (int i=1; i<=n; i++) 
    		for (int j=i; j<=n; j++){
    			int mi=1234;
    			for (int o=i; o<=j; o++)	
    				mi=min(mi,a[o]);
    		zz+=mi;		             
    		}
    	
    	
    	if (zz>=ma) ma=zz;
    	co++;
    	for (int i=1; i<=n; i++)  {
    		b[co][i]=a[i];         
    	}
    	b[co][n+1]=zz;	
    } else {
        for (int i = 1; i <= n; i++)
            if (!ok[i]) {
                ok[i] = 1;
                a[v] = i;
                rec(v+1);
                ok[i] = 0;
            }
    }   
}

 
 
int main()
{
 
    cin>>n>>k;
    rec(1);
    z=0;
    for (int i=1; i<=co; i++)  {
    	if (b[i][n+1]==ma) z++; 
    	if (z==k) {
    		for (int j=1; j<=n; j++)
    			cout<<b[i][j]<<" ";
    		exit(0);
    	}	
    	
    }
    return 0;
}