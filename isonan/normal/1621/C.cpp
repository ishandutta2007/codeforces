#include <cstdio>

bool vis[10010];
int p[10010];
int stk[10010],top;
void Q(int x){
	printf("? %d\n",x);
	int ans;
	fflush(stdout);
	scanf("%d",&ans);
	stk[top]=ans;
	++top;
}
int main(){
	int t,n;
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				top=0;
				for(;;){
					Q(i);
					++cnt;
					if(top>1&&stk[top-1]==stk[0])break;
				}
				--top;
				for(int i=0;i<top;++i){
					p[stk[i]]=stk[(i+1)%top];
					vis[stk[i]]=1;
				}
			}
		}
		printf("! ");
		for(int i=1;i<=n;++i)printf("%d ",p[i]);putchar('\n');
		fflush(stdout);
	}
}