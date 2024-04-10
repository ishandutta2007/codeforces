#include <cstdio>

int n;
int a[100001];
int main(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),cnt+=(a[i]%2)?1:0;
	cnt>>=1;
	for(int i=1;i<=n;i++){
		if(a[i]%2){
			if(cnt)a[i]=(a[i]+1)>>1,--cnt;
			else a[i]=(a[i]-1)>>1;
		}
		else a[i]=a[i]>>1;
		printf("%d\n",a[i]);
	}
}