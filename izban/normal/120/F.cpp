#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;
int n,ans,ni,a1;
int a[100][100];
bool vis[100];
void dfs(int x,int v) {
	vis[v]=true;
	a1=max(a1,x);
	for (int i=0; i<ni; i++) {
		if (a[v][i]==1 && !vis[i]) dfs(x+1,i);
	}
	vis[v]=false;
}
int main() {
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	cin >> n; ans=0;
	for (int k=0; k<n; k++) {
		cin >> ni;
		a1=0;
		for (int i=0; i<ni; i++)
			for (int j=0; j<ni; j++)
				a[i][j]=0;
		for (int i=1; i<ni; i++) {
			int b,c;
			cin >> b >> c;
			a[b-1][c-1]=1;
			a[c-1][b-1]=1;
		}
		ans=ans;
		for (int i=0; i<ni; i++) {
			for (int j=0; j<n; j++) vis[j]=false;
			dfs(0,i);
		}
		ans+=a1;
	}
	cout << ans;
	return 0;
}