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
int n,m,a[123],b[213],zz,k,ma ,mi,z;

string s[123],l[123],x;
int main()
{
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>a[i];
	for (int j=0; j<m; j++)
		cin>>s[j];

	for (int i=0; i<m; i++) { 
		z=1;
		for (int j=0; j<m; j++)
			if ((s[i]!="0") && s[i]==s[j] && i!=j)  {z++; s[j]="0";}
		if (s[i]!="0")  {s[i]="0"; b[zz++]=z;}
	}
    sort(a,a+n);	
	sort(b,b+zz);   
	for (int i=zz-1; i>=0; i--) {
		n--;
		ma+= b[i]*a[n];
	    mi+= b[i]*a[k];
	    k++;
	}
	cout<<mi<<" "<<ma;
		


	return 0;
}