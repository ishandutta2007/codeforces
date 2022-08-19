#include <cstdio>
#include <algorithm>

int n,stk[100001],top;
double x,y;
struct point{
	double x,y;
}num[100001];
bool cmp(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y>b.y);
}
bool getline(int a,int b,int c){
	double k=(num[a].y-num[b].y)/(num[a].x-num[b].x),B=num[a].y-k*num[a].x;
	return num[c].x*k+B>=num[c].y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&x,&y),num[i]=(point){x,y-x*x};
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i>1&&num[i].x==num[i-1].x)continue;
		while(top>1&&getline(stk[top-1],i,stk[top]))--top;
		stk[++top]=i;
	}
	printf("%d\n",top-1);
}