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

int n,m,a[1234][1234],p,k,d,z;


int main(){
	cin>>n>>k;                
	for (int i=1; i<=n; i++) {
		a[i][i]=k;	
	}
	for (int i=1; i<=n; i++)  {
		for(int j=1; j<=n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
		

	return 0;
}