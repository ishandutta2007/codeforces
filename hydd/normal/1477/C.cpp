#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,lst,now,x[5100],y[5100]; bool vis[5100];
ll dis(int a,int b){
	return 1ll*(x[b]-x[a])*(x[b]-x[a])+1ll*(y[b]-y[a])*(y[b]-y[a]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	lst=1; vis[1]=true; printf("1");
	for (int i=1;i<n;i++){
		now=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&(!now||dis(lst,now)<dis(lst,j))) now=j;
		vis[now]=true; lst=now; printf(" %d",now);
	}
	return 0;
}