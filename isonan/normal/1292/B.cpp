#include <cstdio>
#include <algorithm>

long long x0,y0,ax,ay,bx,by,sx,sy,t;
long long nodes[2][10001],top;
long long abs(long long x){
	return x<0?-x:x;
}
long long dist(long long x1,long long y1,long long x2,long long y2){
	return abs(x1-x2)+abs(y1-y2);
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&sx,&sy,&t);
	top=1;
	nodes[0][1]=x0;
	nodes[1][1]=y0;
	for(;;){
		++top;
		nodes[0][top]=nodes[0][top-1]*ax+bx;
		nodes[1][top]=nodes[1][top-1]*ay+by;
		if(nodes[0][top]>sx+t||nodes[1][top]>sy+t){
			--top;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=top;i++){
		long long dis=dist(sx,sy,nodes[0][i],nodes[1][i]),tem=dis;
		if(dis>t){
			continue;
		}
		else ans=std::max(ans,1);
		for(int j=i-1;j>=1;j--){
			tem+=dist(nodes[0][j],nodes[1][j],nodes[0][j+1],nodes[1][j+1]);
			if(tem>t)continue;
			else ans=std::max(ans,i-j+1);
		}
		tem=dis;
		for(int j=i+1;j<=top;j++){
			tem+=dist(nodes[0][j],nodes[1][j],nodes[0][j-1],nodes[1][j-1]);
			if(tem>t)continue;
			else ans=std::max(ans,j-i+1);
		}
	}
	printf("%d\n",ans);
}