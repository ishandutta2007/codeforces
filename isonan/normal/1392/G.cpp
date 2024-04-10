#include <cstdio>
#include <algorithm>

int m,n,k;
int s1,s2;
int num[20];
int f[1048576][21],a[1000001],b[1000001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int lim;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	lim=1<<k;
	for(int i=0,tem;i<k;++i){
		scanf("%1d",&tem);
		if(tem)s1|=1<<i;
	}
	for(int i=0,tem;i<k;++i){
		scanf("%1d",&tem);
		if(tem)s2|=1<<i;
	}
	for(int i=1;i<=n;++i)
		a[i]=read()-1,b[i]=read()-1;
	for(int i=0;i<k;++i)num[i]=i;
	for(int i=n;i;--i){
//		printf("%d %d\n",i,s2);
//		for(int i=0;i<k;++i)printf("%d ",num[i]);putchar('\n');
		f[s2][0]=std::max(f[s2][0],i);
		if(((s2&(1<<num[a[i]]))!=0)!=((s2&(1<<num[b[i]]))!=0))
			s2^=(1<<num[a[i]])^(1<<num[b[i]]);
		std::swap(num[a[i]],num[b[i]]);
	}
	for(int i=1,l=1;i<lim;i<<=1,++l)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;++k){
				int *a=f[j+k],*b=f[i+j+k];
				for(int m=l;m;--m)
					a[m]=std::max(a[m],b[m-1]),
					b[m]=std::max(b[m],a[m-1]);
			}
	int ans=0,l=1,r=n;
	for(int i=0;i<k;++i)num[i]=i;
	for(int i=n;i;--i){
		if(((s1&(1<<num[a[i]]))!=0)!=((s1&(1<<num[b[i]]))!=0))
			s1^=(1<<num[a[i]])^(1<<num[b[i]]);
		std::swap(num[a[i]],num[b[i]]);
		for(int j=k;~j&&j>ans;--j)
			if(f[s1][k-j]-i+1>=m)
				ans=j,l=i,r=f[s1][k-j];
	}
	printf("%d\n%d %d",ans,l,r);
}