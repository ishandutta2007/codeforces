#include <cstdio>
#include <vector>

int t,n;
int a[1001],pre[1001],start[1001];
int stk[1001],top;
std::vector<int>ans[1001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		top=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]>1){
				while(a[stk[top]]!=a[i]-1){
					pre[start[stk[top]]]=stk[top-1];
					--top;
				}
				pre[i]=stk[top];
				start[i]=start[stk[top]];
				stk[top]=i;
			}
			else{
				start[i]=i;
				stk[++top]=i;
			}
		}
		for(int i=1;i<top;++i)pre[start[stk[i+1]]]=stk[i];
		ans[1].clear();
		ans[1].push_back(1);
		puts("1");
		for(int i=2;i<=n;++i){
			if(a[i]==1){
				ans[i]=ans[pre[i]];
				ans[i].push_back(1);
			}
			else{
				ans[i]=ans[pre[i]];
				++ans[i].back();
			}
			for(int j=0;j<ans[i].size();++j){
				printf("%d",ans[i][j]);
				if(j+1<ans[i].size())putchar('.');
				else putchar('\n');
			}
		}
	}
}