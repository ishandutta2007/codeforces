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
int n,k,a,b,c,g[500][500];
int main() {
	cin>>n;
	for (int i=1; i<=n; i++) 
	for (int j=1; j<=n; j++) {
		cin>>g[i][j];
	}
	cin>>k;
	for (int l=1; l<=k; l++) {
		cin>>a>>b>>c;                  
		long long s=0;
		for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) {
			g[i][j]=min(g[i][j],g[i][a]+c+g[b][j]);
			g[i][j]=min(g[i][j],g[i][b]+c+g[a][j]);
			s+=g[i][j];
		}
		
	if (l>1) cout<<" ";	
	cout<<s/2;
	}
	return 0;
}