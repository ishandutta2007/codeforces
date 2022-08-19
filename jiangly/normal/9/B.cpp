#include<bits/stdc++.h>
const int MAXN=100;
int n,v_b,v_s;
int x[MAXN+5],x_u,y_u;
int ans;
int main(){
	scanf("%d%d%d",&n,&v_b,&v_s);
	ans=n;
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	scanf("%d%d",&x_u,&y_u);
	for(int i=n-1;i>=2;--i)
		if(v_s*x[i]+v_b*sqrt(1ll*(x_u-x[i])*(x_u-x[i])+1ll*y_u*y_u)<v_s*x[ans]+v_b*sqrt(1ll*(x_u-x[ans])*(x_u-x[ans])+1ll*y_u*y_u))
			ans=i;
	printf("%d\n",ans);
	return 0;
}