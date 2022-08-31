#include <cstdio>
#include <algorithm>

int t,n,a[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int mx=-0x7f7f7f7f,x=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i); 
			if(i>1)x=std::max(x,mx-a[i]);
			mx=std::max(mx,a[i]);
		}
		int cnt=0;
		while(x)x>>=1,++cnt;
		printf("%d\n",cnt);
	}
}