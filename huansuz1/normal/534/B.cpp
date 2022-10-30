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

int s,v1,v2,t,d,n,a[123456];
int main(){
cin>>v1>>v2>>t>>d;
a[1]=v1;
a[t]=v2;
n=t;
for (int i=2; i<n; i++)
	a[i]=d+a[i-1];
for (int i=n-1; i>=2; i--)
	if (abs(a[i+1]-a[i])>d) {
		a[i]=a[i+1]+d;
	}
for (int i=1; i<=n; i++)
	s+=a[i];
cout<<s;


	
	

}