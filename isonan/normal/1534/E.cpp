#include <cstdio>

int n,k;
int f[501];
int q[501],h,t,pre[501],v[501];
int stk[501],top;
bool vis[501];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;++i)f[i]=501;
	f[0]=0;
	q[++t]=0;
	while(h<t){
		++h;
//		printf("%d\n",)
		for(int i=0;i<=k&&i<=q[h];++i)
			if((k-i)<=n-q[h]){
				int u=q[h]-i+(k-i);
				if(f[u]==501){
					f[u]=f[q[h]]+1;
					pre[u]=q[h];
					v[u]=i;
					q[++t]=u;
				}
			}
	}
	if(f[n]==501){
		puts("-1");
		fflush(stdout);
		return 0;
	}
	int tem=n;
	while(tem){
		stk[++top]=tem;
		tem=pre[tem];
	}
	int tot=0;
	for(int i=top;i;--i){
		int cnt1=v[stk[i]],cnt2=k-cnt1;
		printf("? ");
		for(int j=1;j<=n;++j)
			if(vis[j]&&cnt1){
				vis[j]=0;
				--cnt1;
				printf("%d ",j);
			}
			else if(!vis[j]&&cnt2){
				vis[j]=1;
				--cnt2;
				printf("%d ",j);
			}
		putchar('\n');
		fflush(stdout);
		int tem;
		scanf("%d",&tem);
		tot^=tem;
	}
	printf("! %d\n",tot);
		fflush(stdout);
}