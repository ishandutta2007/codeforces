#include <cstdio>

int t,n,k,a[100001],b[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		bool cando=0;
		for(int i=1;i<=n;i++)if(a[i]==k)cando=1;
		if(!cando){
			puts("no");
			continue;
		}
		if(n==1){
			puts("yes");
			continue;
		}
		cando=0;
		int mn=0x7f7f7f7f;
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+((a[i]>=k)?1:-1);
			if(b[i]>mn)cando=1;
			if(mn>b[i-1])mn=b[i-1];
		}
		if(cando){
			puts("yes");
		}
		else{
			puts("no");
		}
	}
}