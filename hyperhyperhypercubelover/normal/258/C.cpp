#include<cstdio>
#include<algorithm>

#define mod 1000000007

int f(int x,int y)
{
	if(y==0)return 1;
	if(y&1)return 1LL*f(x,y-1)*x%mod;
	y=f(x,y>>1);
	return 1LL*y*y%mod;
}

int a[100000];
int b[1000];

int main()
{
	int ttt;
    int i,j,k,n,tmp,tmp2,res,cnt;
    int ptr1,ptr2;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    std::sort(a,a+n);
    res=0;
    for(i=1;i<=100000;i++)
	{
		cnt=0;
		for(j=1;j*j<i;j++)if(i%j==0)
		{
			b[cnt++]=j;
			b[cnt++]=i/j;
		}
		if(j*j==i)b[cnt++]=j;
		std::sort(b,b+cnt);
		tmp=1;
        for(j=1;j<cnt;j++)tmp=1LL*tmp*f(j,std::lower_bound(a,a+n,b[j])-std::lower_bound(a,a+n,b[j-1]))%mod;
        tmp=1LL*tmp*(f(cnt,n-(std::lower_bound(a,a+n,b[cnt-1])-a))-f(cnt-1,n-(std::lower_bound(a,a+n,b[cnt-1])-a))+mod)%mod;
		res=(res+tmp)%mod;
	}
	printf("%d",res);
}