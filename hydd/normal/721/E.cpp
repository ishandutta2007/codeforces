#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,p,t,l,r;
int f[110000],g[110000];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d%d%d%d",&L,&n,&p,&t);
	f[0]=0; g[0]=-t;
	int j=1,v,tmp,lst;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l,&r); j--;
		f[i]=f[i-1]; g[i]=g[i-1];
		for (;j<i&&g[j]+t<=r;j++){
			lst=max(l,g[j]+t);
			v=f[j]+(r-lst)/p; tmp=lst+(r-lst)/p*p;
			if (v>f[i]||(v==f[i]&&tmp<g[i])) f[i]=v,g[i]=tmp;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}