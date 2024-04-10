#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m; ll tot,sum;
int main(){
	scanf("%d%d",&n,&m); int x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		tot+=y; sum+=1ll*x*y;
	}
	if (tot<n||tot==n&&sum%n==1ll*n*(n+1)/2%n) puts("1");
	else puts("-1");
	return 0;
}