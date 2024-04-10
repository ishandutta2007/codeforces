#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long

int n,l,t[2000010],x[2000010],y[2000010];
int ans[2][2000010];
struct point{
	int t,x,y;
}num[2000010];
bool cmp(point a,point b){return (a.t%l)<(b.t%l);}
int F(int a,int b){
	a-=((a%b)+b)%b;
	return a/b;
}
int G(int a,int b){
//	printf("%d %d %d\n",a,b,(a-(((a%b)+b)%b))/b+(a%b==0));
	return ((a-(((a%b)+b)%b))/b)+(a%b!=0);
}
void solve(int *ans,int *x){
	int mn=0,mx=l;
//	for(int i=1;i<=n;i++)printf("%d ",x[i]);putchar('\n');
	for(int i=1;i<=n;i++){
		int t=(num[i+1].t%l-num[i].t%l),u=(num[i+1].t/l-num[i].t/l);
		if(i==n){
			t+=l;
			--u;
		}
//		printf("%d %d %d\n",t,u,num[i].t);
		int v=x[i+1]-x[i]+t+l*u;
//		printf("%d\n",v);
		if(v%2){
			puts("NO");
			exit(0);
		}
		v>>=1;
		if(!u){
			if(v<0||v>t){
				puts("NO");
				exit(0);
			}
		}
		else{
			if(u>0){
				mx=std::min(mx,F(v,u));
				mn=std::max(mn,G(v-t,u));
			}
			else{
				mx=std::min(mx,F(t-v,-u));
				mn=std::max(mn,G(-v,-u));
			}
//			if(u>0){
//				mx=std::min(mx,(int)floor((double)v/(double)u));
//				mn=std::max(mn,(int)ceil((double)(v-t)/(double)u));
//			}
//			else{
//				mx=std::min(mx,(int)floor((double)(t-v)/(double)(-u)));
//				mn=std::max(mn,(int)ceil((double)(-v)/(double)(-u)));
//			}
		}
	}
//	printf("%d\n",mn);
	if(mn>mx){
		puts("NO");
		exit(0);
	}
	for(int i=1;i<=n;i++){
		int d=x[i+1]-x[i]-((mn<<1)-l)*(num[i+1].t/l-num[i].t/l);
		int L=(num[i].t%l)+1,R=num[i+1].t%l;
		if(i==n){
			d=(mn<<1)-l-(x[i]-((mn<<1)-l)*(num[i].t/l));
			R=l;
		}
		int m=(d+(R-L+1))>>1;
		for(int j=L;j<=R;j++)
			if(j-L+1<=m)ans[j]=1;
			else ans[j]=-1;
	}
}
signed main(){
	scanf("%lld%lld",&n,&l);
	for(int i=1,t1,t2,t3;i<=n;i++){
		scanf("%lld%lld%lld",&num[i].t,&t2,&t3);
		num[i].x=t2-t3;
		num[i].y=t2+t3;
		if((num[i].t&1)!=(num[i].x&1)||(num[i].t&1)!=(num[i].y&1)){
			puts("NO");
			return 0;
		}
	}
	num[++n]=(point){0,0,0};
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++)x[i]=num[i].x,y[i]=num[i].y;
	solve(ans[0],x);
	solve(ans[1],y);
	for(int i=1;i<=l;i++){
		if(ans[0][i]==1&&ans[1][i]==1)putchar('R');
		else if(ans[0][i]==-1&&ans[1][i]==-1)putchar('L');
		else if(ans[0][i]==1&&ans[1][i]==-1)putchar('D');
		else if(ans[0][i]==-1&&ans[1][i]==1)putchar('U');
//		printf("(%d %d)",ans[0][i],ans[1][i]);
	}
}