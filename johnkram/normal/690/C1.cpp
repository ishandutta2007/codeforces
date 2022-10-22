#include<cstdio>
int f[1005],n,m,i,j;
int get(int x)
{
    if(!f[x])return x;
    return f[x]=get(f[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    if(m!=n-1)
    {
        puts("no");
        return 0;
    }
    while(m--)
    {
        scanf("%d%d",&i,&j);
        if(get(i)==get(j))
        {
            puts("no");
            return 0;
        }
        f[get(i)]=get(j);
    }
    puts("yes");
    return 0;
}