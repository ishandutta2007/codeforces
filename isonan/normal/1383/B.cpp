#include <cstdio>

int t,n,a[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		bool cando=0;
		for(int i=30;~i;--i){
			int cnt1=0,cnt2=0;
			for(int j=1;j<=n;j++)
				if(a[j]&(1<<i))++cnt1;
				else ++cnt2;
			if(cnt1%2==1){
				cando=1;
				if(cnt2%2==1||(cnt1/2)%2==0)puts("WIN");
				else puts("LOSE");
				break;
			}
		}
		if(!cando)puts("DRAW");
	}
}