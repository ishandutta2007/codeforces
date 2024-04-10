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

int n,m,l[123],r[123],t[123],c[123],a[123],b[123],s;

int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		a[i]=1001;
		b[i]=0;
	}
	for (int i=0; i<m; i++)  {
		cin>>l[i]>>r[i]>>t[i]>>c[i];
		for (int j=l[i]; j<=r[i]; j++)
			if (a[j]>t[i]) {a[j]=t[i]; b[j]=c[i];} 
	}
	
	for (int j=1; j<=n; j++)
		s+=b[j];
		cout<<s;
                                


	return 0;
}