#include<cstdio>
using namespace std;
int n,m=1,k,color[1005][1005];
bool check(int x)
{
    int tmp=1;
    for(int i=1;i<=x;i++)
    {
        tmp=tmp*k;
        if(tmp>=n) return true;
    }
    return false;
}
void Work(int col,int lim,int L,int R)
{
//    printf("working %d %d %d %d\n",col,lim,L,R);
    if(L==R) return;
    int Blen=(R-L+1)/lim,Extra=(R-L+1)%lim;
    int Now=L;
    for(int i=1;i<=lim;i++)
    {
        if(i>Extra && Blen==0) return;
        int NowLen=Blen + (i<=Extra ? 1 : 0);
        for(int j=Now;j<=Now+NowLen-1;j++)
        {
            for(int x=Now+NowLen;x<=R;x++)
            {
                color[j][x]=col;
            }
        }
        Work(col-1,lim,Now,Now+NowLen-1);
        Now+=NowLen;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    while(!check(m))
    {
        m++;
    }
    printf("%d\n",m);
    Work(m,k,1,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("%d ",color[i][j]);
        }
    }
}