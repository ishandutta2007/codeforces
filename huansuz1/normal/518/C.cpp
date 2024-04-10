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

long long a[123456],b[123456],n,m,k,x,s;	

int main(){
cin>>n>>m>>k;
for (int i=1; i<=n; i++){
	cin>>x;
	b[i]=x; 
	a[x]=i;
}
for (int i=0; i<m; i++){
	cin>>x;
	
	s+=a[x]/k;
	if (a[x]%k!=0) s++;
	if (a[x]!=1 && b[1]!=x){
		swap(b[a[x]],b[a[x]-1]);
		swap(a[x],a[b[a[x]]]);

	}
}
cout<<s;




}