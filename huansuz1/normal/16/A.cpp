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

int n,m,b[123],z;
char a[123][123];

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++) {
	    for (int j=0; j<m; j++) {
			cin>>a[i][j];       
			if (a[i][0]==a[i][j]) b[i]++;
		}
		if (b[i]==m) z++;
	}
	if (z==n) {
		for (int i=0; i<n-1; i++)
			if (a[i][0]!=a[i+1][0]) z--;
		if (z==1) cout<<"YES"; else cout<<"NO";
	} else cout<<"NO"	;  

	return 0;
}