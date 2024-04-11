#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int m; cin>>m;
	int a[m], b[m], c[m], d[m]; 
	
	for (int &i:a) cin>>i; 
	for (int &i:b) cin>>i;
 
	iota(c,c+m,0);
	sort(c,c+m,[&](int i,int j){ return b[i]<b[j]; });
	sort(a,a+m,greater<int>());
 
	for (int i=0; i<m; i++) d[c[i]]=a[i];
	for (int i:d) cout<<i<<" "; 
}