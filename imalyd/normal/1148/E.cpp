#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,t,d;
long long s;
int a[N],c[N],b[N];
pair<int,int>p[N];
int x[N],y[N],z[N];
void pse(){
	int tim=time(0)+2;
	while(time(0)<tim);
}
int main(){
//	freopen("2.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].first);
		p[i].second=i;
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(p+1,p+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		s+=(a[i]=p[i].first-b[i]);
		c[i]=p[i].second;
	}
	if(s!=0ll){printf("NO");return 0;}
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	for(int i=1,j=1;i<=n;i++){
		if(a[i]>0){printf("NO");return 0;}
		while(a[i]<0){
			if(j<i)j=i;
			while(j<=n&&a[j]<=0)++j;//printf("j=%d\n",j);
			d=min(-a[i],a[j]);
			a[i]+=d;
			a[j]-=d;
//			printf("op %d %d %d\n",i,j,d);
//			pse();
			x[++t]=c[i];
			y[  t]=c[j];
			z[  t]=d   ;
		}
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	}
	printf("YES\n%d",t);
	for(int i=1;i<=t;i++)printf("\n%d %d %d",x[i],y[i],z[i]);
	return 0;
}