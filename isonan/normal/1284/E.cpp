#include <algorithm>
#include <cstdio>
#include <cmath>

int n,x[2501],y[2501],top;
long long ans=0;
long double rad[2501];
long long C3(long long x){
	if(x<=0)return 0;
	return (1ll*x*(x-1)*(x-2))/6ll;
}
struct point{
	int x,y;
	long double ang;
}num[2501];
bool cmp(const point &a,const point &b){
	return a.ang<b.ang;
}
bool sameside(int a,int b){
	return (1ll*num[a].y*num[b].x)-(1ll*num[a].x*num[b].y)<0ll;
}
int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=n;j++)
			if(i!=j)num[++top]=(point){x[j]-x[i],y[j]-y[i],std::atan2(y[i]-y[j],x[i]-x[j])};
		std::sort(num+1,num+top+1,cmp);
		ans+=(1ll*top*(top-1)*(top-2)*(top-3))/24ll;
		for(int j=1;j<=top;j++){
			int p;
			if(num[top].ang-num[j].ang<(long double)3.14159265358979323846){
				p=std::lower_bound(num+1,num+top+1,(point){0,0,num[j].ang-(long double)3.14159265358979323846},cmp)-num;
				while(p<=top&&!sameside(p,j))++p;
				while(p&&sameside(p-1,j))--p;
				ans-=C3(j-p);
			}
			else{
				p=std::lower_bound(num+1,num+top+1,(point){0,0,num[j].ang+(long double)3.14159265358979323846},cmp)-num;
				while(p<=top&&!sameside(p,j))++p;
				while(p&&sameside(p-1,j))--p;
				ans-=C3(top+j-p);
			}
		}
	}
	printf("%lld\n",ans);
}