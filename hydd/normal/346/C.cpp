#include<bits/stdc++.h>
using namespace std;
int n,x[110000],a,b;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1); n=unique(x+1,x+n+1)-x-1;
	
	scanf("%d%d",&a,&b); int ans=0;
	while (a>b){
		int c=a-1,v,m=0;
		for (int i=1;i<=n;i++){
			v=a-a%x[i];
			if (v>=b) c=min(c,v),x[++m]=x[i];
		}
		n=m; a=c; ans++;
	}
	printf("%d\n",ans);
	return 0;
}