#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n,m,k,b[2345];
char a[2345][2345];

int main(){
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>a[i][j];
			if (a[i][j]=='L' && j-i+1>=1) b[j-i+1]++;
			if (a[i][j]=='R' && j+i-1<=m) b[j+i-1]++;
			if (a[i][j]=='U' && i%2==1) b[j]++;    
			if (a[i][j]=='D' && i==1) b[j]+=n;
		}
	}
	for (int i=1; i<=m; i++)
		cout<<b[i]<<" ";


}