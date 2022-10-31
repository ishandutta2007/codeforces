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

int n,m,b[123],z,a[123],s,sum;

int main(){
	cin>>n>>m;
	for (int i=0; i<m; i++)
		cin>>a[i]>>b[i];
	for (int i=0; i<m; i++)
		for (int j=0; j<m; j++)
			if (b[i]>b[j]) { int p=b[i]; b[i]=b[j]; b[j]=p;
			                     p=a[i]; a[i]=a[j]; a[j]=p;
			}
	for (int i=0; i<m; i++)  {
		s+=a[i];
		if (s<n) sum+=a[i]*b[i]; else {
			s-=a[i];
			sum+=(n-s)*b[i];
			break;
		}
	}
	cout<<sum;
	
	
	return 0;
}