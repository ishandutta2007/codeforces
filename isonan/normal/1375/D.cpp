#include <cstdio>
#include <set>

int t,n,a[1001],cnt[1001],stk[2010],top;
int getmex(){
	int ans=0;
	while(cnt[ans])++ans;
	return ans;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		top=0;
		for(int i=0;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),++cnt[a[i]];
		for(int i=n;i;i--){
			int v=getmex();
			if(v<n){
				stk[++top]=v+1;
				--cnt[a[v+1]];
				a[v+1]=v;
				++cnt[v];
			}
			else break;
		}
		for(int i=1;;i++){
			if(getmex()<n){
				int v=getmex();
				stk[++top]=v+1;
				--cnt[a[v+1]];
				a[v+1]=v;
				++cnt[v];
			}
			else{
				int p=-1;
				for(int j=1;j<=n;j++){
					if(a[j]!=j-1){
						p=j;
						break;
					}
				}
				if(!~p)break;
				int v=getmex();
				stk[++top]=p;
				--cnt[a[p]];
				a[p]=v;
				++cnt[v];
			}
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
		}
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d ",stk[i]);putchar('\n');
	}
}