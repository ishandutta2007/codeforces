#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
                                                                        	
using namespace std;

int n,a[56789],b[5678],z;
int main(){
cin>>n;
if (n==3) {
	cout<<2<<endl<<1<<" "<<3;
	exit(0);
} 
if (n==2 || n==1) {
	cout<<1<<endl<<1;
	exit(0);
} 
for (int i=2; i<=n; i+=2)
	b[z++]=i;
for (int i=1; i<=n; i+=2)
	b[z++]=i;
cout<<z<<endl;
for (int i=0; i<z; i++)
	cout<<b[i]<<" ";
	
	

}