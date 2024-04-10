#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];

void dfs(int x,int y){
	
	if(x>n){if(!(y%360)){puts("YES");exit(0);}return;}
	dfs(x+1,y+a[x]);
	dfs(x+1,y-a[x]);
}

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	puts("NO");
}