#include<cstdio>
#include<algorithm>

char a[111111];

int main()
{
	int A,C,G,T;
	int i,n,res,cnt=0;
	scanf("%d",&n);
	scanf("%s",a);
	A=C=G=T=0;
	for(i=0;i<n;i++)
	{
        if(a[i]=='A')A++;
        if(a[i]=='C')C++;
        if(a[i]=='G')G++;
        if(a[i]=='T')T++;
	}
    res=std::max(std::max(A,C),std::max(G,T));
    if(A==res)cnt++;
    if(C==res)cnt++;
    if(G==res)cnt++;
    if(T==res)cnt++;
    res=1;
    for(i=0;i<n;i++)res=1LL*res*cnt%1000000007;
    printf("%d",res);
	return 0;
}