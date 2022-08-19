#include <cmath>
#include <cstdio>
#include <algorithm>

int a[400001],n,I,b[400001],orig[400001];
int main(){
	scanf("%d%d",&n,&I);
	for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i];
	std::sort(a+1,a+n+1);
	int lim=std::unique(a+1,a+n+1)-a-1,tem=1;
	for(int i=1;i<=n;i++)++b[std::lower_bound(a+1,a+lim+1,orig[i])-a];
	for(int i=1;i<=lim;i++)b[i]+=b[i-1];
	int lg=(I*8)/n;
	for(int i=1;i<=lg;i++,tem<<=1){
		if(tem>=lim)break;
	}
	if(tem>=lim)puts("0");
	else{
		int ans=n;
		for(int i=0;i+tem<=lim;i++){
			ans=std::min(ans,b[i]+b[lim]-b[i+tem]);
		}
		printf("%d\n",ans);
	}
}