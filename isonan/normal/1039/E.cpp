#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

int n,w,q,x[100010],bl,top,Next[100010],walk[100010],len[100010],tem[100010];
int mx[100010][21],mn[100010][21],Log[100010];
int rnext[100010];
bool vis[100010];
int ans[100010];
struct que{
	int k,ord;
}num[6000001];
bool cmp(que a,que b){return a.k>b.k||(a.k==b.k&&a.ord>b.ord);}
int val(int l,int r){
	int K=Log[r-l+1];
	return std::min(mn[l][K],mn[r-(1<<K)+1][K])+w-std::max(mx[l][K],mx[r-(1<<K)+1][K]);
}
bool check(int l,int r,int k){
	return k<=val(l,r);
}
int jump(int l,int k){
	int r=l;
	for(int i=16;~i;--i)
		if(r+(1<<i)<=n&&check(l,r+(1<<i),k))r+=1<<i;
//	printf("jump %d %d %d\n",l,k,r);
	return r+1;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&w,&q);
	for(int i=1;i<=n;i++)scanf("%d",x+i);
	Log[1]=0;
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++)mn[i][0]=mx[i][0]=x[i];
	for(int j=1;j<=16;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			mn[i][j]=std::min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]),
			mx[i][j]=std::max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
//	for(int i=1;i<=n;i++)printf("%d ",x[i]);putchar('\n');
	x[n+1]=0x7f7f7f7f;
	for(int i=1;i<=q;i++)scanf("%d",&num[i].k),num[i].ord=-i;
	top=q;
	bl=std::max(1,(int)pow(n,0.3333));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=bl&&i+j<=n;j++)
			num[++top]=(que){val(i,i+j),i};
	std::sort(num+1,num+top+1,cmp);
	for(int i=1;i<=n;i++)Next[i]=rnext[i]=i+1,walk[i]=std::min(n+1,i+bl),len[i]=walk[i]-i;
	for(int i=1;i<=top;i++)
		if(num[i].ord>0){
			int u=num[i].ord;
			++Next[u];
			int l=std::max(1,u-bl);
			vis[u]=1;
			tem[u]=0;
			for(int j=u-1;j>=l;--j){
				vis[j]=(Next[j]<=u&&vis[Next[j]]);
				if(vis[j])tem[j]=tem[Next[j]]+1;
			}
			for(int j=l,now=u,v=0;j<=u;j++)
				if(vis[j]){
					while(now<=n&&Next[now]-j<=bl)now=Next[now],++v;
					walk[j]=now;
					len[j]=tem[j]+v;
				}
		}
		else{
			int now=1;
//			for(int i=1;i<=n;i++)printf("%d %d %d %d\n",i,Next[i],walk[i],len[i]);
			for(;now<=n;){
				ans[-num[i].ord]+=len[now];
				now=walk[now];
				if(now!=n+1){
					while(rnext[now]<=n&&rnext[now]-now<=bl*bl&&check(now,rnext[now],num[i].k))++rnext[now];
					if(rnext[now]-now>bl*bl)now=jump(now,num[i].k);
					else now=rnext[now];
					++ans[-num[i].ord];
				}
//				printf("%d %d\n",now,ans[-num[i].ord]);
			}
		}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]-1);
}