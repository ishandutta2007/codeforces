#include<bits/stdc++.h>
using namespace std;
int n,m[500001],j,k,i,z;
int main(){
	cin>>n>>z;
	for(i=0;i<n;i++)
		cin>>m[i];
	sort(m,m+n);
	for(j=1;j<n;j++)
		if(m[j]-z>=m[k])
			k++;
	cout<<min(k,n/2);
}