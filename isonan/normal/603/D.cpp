#include <bits/stdc++.h>
#define double long double

struct point{
	double x,y,v;
}p[2001],num[2001];
int a[2001],b[2001],c[2001],V[2001];
bool cmp(point a,point b){
	return a.v<b.v;
}
bool same(int x,int y){
	return 
		1ll*(a[x]*c[x])*(a[y]*a[y]+b[y]*b[y])==1ll*(a[y]*c[y])*(a[x]*a[x]+b[x]*b[x])&&
		1ll*(b[x]*c[x])*(a[y]*a[y]+b[y]*b[y])==1ll*(b[y]*c[y])*(a[x]*a[x]+b[x]*b[x]);
}
bool samex(int x,int y){
	return 
		1ll*(a[x]*c[x])*(a[y]*a[y]+b[y]*b[y])==1ll*(a[y]*c[y])*(a[x]*a[x]+b[x]*b[x]);
}
bool cross(point a,point b){
	return fabs(a.x*b.y-b.x*a.y)>1e-12;
}
int n,top;
int main(){
	scanf("%d",&n);
	for(int i=1,a,b,c;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		::a[i]=a;
		::b[i]=b;
		::c[i]=c;
		V[i]=a*a+b*b;
		p[i]=(point){(double)(a*c),(double)(b*c),0};
//		printf("%Lf %Lf\n",p[i].x,p[i].y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=n;j++)
			if(i!=j){
				if(same(i,j))ans+=n-2;
				else{
					num[++top]=(point){p[i].x*(double)V[j]-p[j].x*(double)V[i],p[i].y*(double)V[j]-p[j].y*(double)V[i]};
					if(num[top].x<0||(samex(i,j)&&num[top].y<0))num[top].x=-num[top].x,num[top].y=-num[top].y;
					num[top].v=atan2(num[top].y,num[top].x);
				}
			}
//		printf("%d\n",top);
		std::sort(num+1,num+top+1,cmp);
		for(int j=1,last=0;j<=top;j++){
//			printf("%Lf %Lf\n",num[j].x,num[j].y);
			if(j>1&&cross(num[j],num[j-1]))last=0;
			ans+=last;
			++last;
		}
//		printf("%d\n",ans);
	}
	printf("%d\n",ans/3);
}