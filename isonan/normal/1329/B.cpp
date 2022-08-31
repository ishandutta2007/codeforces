#include <cstdio>
#include <cstring>
#include <algorithm>

int t,d,m,g[31];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&d,&m);
		memset(g,0,sizeof g);
		for(int i=0;i<30;i++)
			if((1<<i)<=d)g[i]=std::min((1<<(i+1))-1,d)-(1<<i)+1;
		int ans=1;
		for(int i=1;i<30;i++)ans=(1ll*(ans+1)*g[i]%m+ans)%m;
		printf("%d\n",ans);
	}
}