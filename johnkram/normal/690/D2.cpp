#include<cstdio>
#include<cstring>
#define P 1000003
#define ll long long
int n,m,f[700005],i;
int Pow(int a,int b)
{
    int s=1;
    for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
    return s;
}
int main()
{
    scanf("%d%d",&n,&m);
    n+=m;
    for(i=f[0]=1;i<=n;i++)f[i]=(ll)f[i-1]*i%P;
    i=(ll)f[n]*Pow(f[m],P-2)%P*Pow(f[n-m],P-2)%P-1;
    if(i<0)i+=P;
    printf("%d\n",i);
    return 0;
}