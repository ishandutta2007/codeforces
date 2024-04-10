// Hydro submission #61a313139a8856088049638d@1638077203653
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node1{
	int x,y,num;
}a[100039];
struct node2{
	int x,num;
}b[100039];
inline bool cmp1(node1 x,node1 y){return x.y>y.y;}
inline bool cmp2(node2 x,node2 y){return x.x<y.x;}
int n,m,ans,tot;
int flag[100039],ans1[100039],ans2[100039];
int main(){
//	freopen("booking.in","r",stdin);
//	freopen("booking.out","w",stdout);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&b[i].x);
		b[i].num=i;	
	}
	sort(b+1,b+m+1,cmp2);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(!flag[j]/**/&&a[i].x<=b[j].x/**/){
				flag[j]=1;//
				ans+=a[i].y;//
				tot++;
				ans1[tot]=a[i].num;
				ans2[tot]=b[j].num;
				break;
			}
	//printf("%d",ans);
	printf("%d %d\n",tot,ans);
	for(i=1;i<=tot;i++)
		printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}