#include<cstdio>

int a[30000];

int main()
{
    int i,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)scanf("%d",&a[i]);
    i=1;
    while(i<m)i+=a[i];
    puts(i==m?"YES":"NO");
}