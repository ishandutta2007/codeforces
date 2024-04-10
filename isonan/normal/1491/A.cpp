#include <cstdio>

int n,q,a[100001];
int main(){
	scanf("%d%d",&n,&q);
	int cnt=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),cnt+=a[i];
	for(int i=1;i<=q;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		if(t1==1){
			if(a[t2])--cnt;
			else ++cnt;
			a[t2]^=1;
		}
		else{
			printf("%d\n",t2<=cnt);
		}
	}
}