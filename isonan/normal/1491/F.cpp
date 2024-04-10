#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <windows.h>

int t,stk[21],top,n,p1,p2,P[10001];
int ans[10001],Ans,L[10001],R[10001],val;
bool vis[10001];
bool solved;
int a[10001];
int cnt;
int check(int l,int r,int i){
	if(l==r)return l;
	int mid=(l+r)>>1;
	printf("? %d %d\n",mid-l+1,1);
	for(int i=l;i<=mid;i++)printf("%d ",i);putchar('\n');
	printf("%d\n",i);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	if(y==val)return check(l,mid,i);
	else return check(mid+1,r,i);
}
int main(){
	scanf("%d",&t);
	srand(time(0));
	for(int fd=1;fd<=t;fd++){
		memset(ans,0,sizeof ans);
		memset(vis,0,sizeof vis);
		cnt=0;
		solved=0;
		scanf("%d",&n);
		int p=0,cnt=0;
		for(int i=2;i<=n;i++){
			printf("? %d %d\n",i-1,1);
			for(int j=1;j<i;j++)printf("%d ",j);putchar('\n');
			printf("%d\n",i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x){
				val=x;
				p=check(1,i-1,i);
				cnt=i-2;
				for(int j=1;j<i;j++)if(j!=p)ans[j]=1;
				for(int j=i+1;j<=n;j++){
					printf("? 2 1\n%d %d\n%d\n",j,p,i);
					fflush(stdout);
					int y;
					scanf("%d",&y);
					if(x==y)ans[j]=1,++cnt;
				}
				break;
			}
		}
		printf("! %d ",cnt);
		for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);putchar('\n');
		fflush(stdout);
	}
}