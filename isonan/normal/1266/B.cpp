#include <cstdio>

int n;
long long tem;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&tem);
		if(tem<14ll){
			puts("NO");
			continue;
		}
		bool cando=0;
		for(int i=1;i<=6;i++)if(tem>=i&&(tem-i)%14ll==0ll)cando=1;
		if(cando)puts("YES");
		else puts("NO");
	}
}