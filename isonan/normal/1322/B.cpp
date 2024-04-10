#include <cstdio>
#include <algorithm>

int n,a[1000001],b[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	int ans=0;
	for(int i=26;~i;--i){
		long long x=0;
		int p=n+1;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				p=j;
				break;
			}
		}
//		printf("%d\n",p);
		for(int j=1,k=n+1,l=p;j<p;j++){
			while(a[k-1]+a[j]>=(1<<(i+1))&&k>p-1)--k;
			while(a[l-1]+a[j]>=(1<<i)&&l>j)--l;
			while(l<=j)++l;
//			printf("%d %d %d\n",j,k,l);
			x+=k-p+std::max(p-l,0);
		}
		for(int j=p,k=n+1;j<=n;j++){
			while(a[k-1]+a[j]>=(3<<i)&&k>j)--k;
			while(k<=j)++k;
			x+=std::max(n+1-k,0);
		}
//		printf("%d %d\n",i,x);
		if(x&1)ans|=1<<i;
		for(int j=1;j<p;j++)b[j]=a[j];
		for(int j=p;j<=n;j++)b[j]=a[j]^(1<<i);
		int ind1=1,ind2=p;
		for(int j=1;j<=n;j++){
			if(ind1>=p)a[j]=b[ind2++];
			else if(ind2>n)a[j]=b[ind1++];
			else if(b[ind1]>b[ind2])a[j]=b[ind2++];
			else a[j]=b[ind1++];
		}
	}
	printf("%d\n",ans);
}