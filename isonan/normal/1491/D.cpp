#include <cstdio>

int q;
int main(){
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		if(u>v){
			puts("NO");
			continue;
		}
		int cnt1=0,cnt2=0;
		bool ans=0;
		for(int j=0;j<30;++j){
			cnt1+=(u&(1<<j))!=0;
			cnt2+=(v&(1<<j))!=0;
			if(cnt1<cnt2)ans=1;
		}
		if(ans)puts("NO");
		else puts("YES");
	}
}