#include <cstdio>

int t,n,s[200001],ans[200001];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=ans[i];
		if(cnt<0)return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;++i)scanf("%1d",s+i),cnt+=(s[i]==0);
		if(cnt&1){
			puts("NO");
			continue;
		}
		for(int i=1,a=0,b=0;i<=n;++i){
			if(s[i]==1){
				++a;
				if((a<<1)<=(n-cnt))ans[i]=1;
				else ans[i]=-1;
			}
			else{
				++b;
				if(b&1)ans[i]=1;
				else ans[i]=-1;
			}
		}
		if(!check()){
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;++i)if(s[i]==0)ans[i]=-ans[i];
		if(!check()){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;++i)putchar((ans[i]==1)?'(':')');putchar('\n');
		for(int i=1;i<=n;++i)putchar(((ans[i]==1)^(s[i]==0))?'(':')');putchar('\n');
	}
}