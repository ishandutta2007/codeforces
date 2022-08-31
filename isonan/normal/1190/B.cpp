#include <cstdio>
#include <algorithm>

int a[100001],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(int i=n;i;--i)a[i]-=a[i-1];
	++a[1];
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(!a[i]&&a[i-1]<=1){
			puts("cslnb");
			return 0;
		}
		cnt+=(!a[i]);
		if(cnt>1){
			puts("cslnb");
			return 0;
		}
	}
	int p=1,x=0;
	while(a[p]<=1&&p<=n)++p;
	for(int i=p;i<=n;i++){
		if((((a[i]-1)&1)==1)&&(((n-i+1)&1)==1))x^=1;
	}
	if(x)puts("sjfnb");
	else puts("cslnb");
}