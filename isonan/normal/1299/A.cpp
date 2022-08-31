#include <cstdio>
#include <algorithm>

int n,a[100001],v[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=30;~i;i--){
		int cnt=0,p=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i)){
				p=j;
				++cnt;
			}
		if(cnt==1){
			v[p]+=1<<i;
		}
	}
	int mx=1;
	for(int i=2;i<=n;i++)if(v[i]>v[mx])mx=i;
	std::swap(a[mx],a[1]);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
}