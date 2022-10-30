#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, m, was[12345], zz,b[123][123], z;
char a[123][123];
vector<int> ar[12345];

void dfs(int v, int p){
	was[v] = 1;
	int to;
	for (int i = 0; i < ar[v].size(); i++){
		to = ar[v][i];
		if (was[to]==1 && to != p ) { cout<<"Yes"; exit(0); }
		if (!was[to])  dfs(to , v ); 
	}
	was[v]=2;
}

int main(){
	cin>> n>> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin>>a[i][j];
			zz++;
			b[i][j] = zz;

		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[i][j+1])  ar[b[i][j]].push_back(b[i][j+1]);
			if (a[i][j] == a[i][j-1])  ar[b[i][j]].push_back(b[i][j-1]);
			if (a[i][j] == a[i+1][j])  ar[b[i][j]].push_back(b[i+1][j]);
			if (a[i][j] == a[i-1][j])  ar[b[i][j]].push_back(b[i-1][j]);
		}

	for (int i = 1; i <= zz; i++)
		if (!was[i]) { dfs(i, 0); }


	cout<<"No";

	return 0;
}