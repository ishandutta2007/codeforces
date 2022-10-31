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

map<int, int> mp;
int n,m,x[123456],y[123456],c[123456],p,k,d,z,ma,zz,zzz;


int main(){
	cin>>n;                
	for (int i=1; i<=n; i++) {
	    cin>>x[i]>>y[i];
	    mp[x[i]]++;
	}
	for (int i=1; i<=n; i++) {
		int k=mp[y[i]];
		cout<<n-1+k<<" "<<n-1-k<<endl;
	
	}
		

	return 0;
}