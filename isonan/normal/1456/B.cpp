#include <cstdio>
#include <algorithm>

int n,a[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]^=a[i-1];
	int ans=0x7f7f7f7f;
	for(int i=1;i<=n;i++){
		for(int j=i;i-j+1<=60&&j>=1;--j)
			for(int k=i+1;k-i<=60&&k<=n;++k)
				if((a[i]^a[j-1])>(a[k]^a[i]))ans=std::min(ans,k-j-1);
	}
	if(ans==0x7f7f7f7f)puts("-1");
	else printf("%d\n",ans);
}