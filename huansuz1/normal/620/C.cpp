#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;

int n,m,x[321456][2],z,q;
map<ll , int> mp,a;

int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>m;              
		if (mp[m]==1 && a[m]>=q) { x[z][1]=a[m]+1; x[z][2]=i+1; z++; mp[m]=0;q=i; } else
		{ mp[m]=1; a[m]=i;} 
	}
	if (z==0) {cout<<-1; return 0;}

	cout<<z<<endl;
	if (z==1)  {cout<<1<<" "<<n; return 0;}
	if (z!=0) cout<<1<<" "<<x[0][2]<<endl;
	for (int i=1; i<z-1; i++)
		cout<<x[i-1][2]+1<<" "<<x[i][2]<<endl;
	if (z>1) {cout<<x[z-2][2]+1<<" "<<n;}
    return 0;             
}