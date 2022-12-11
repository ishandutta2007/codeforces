#include <cstdio>
#include <cstring>

const int MAX=1001;

struct segment
{
    int c,d;
}xyz[50];
int main()
{
    bool lz[MAX];
    int p,q,l,r,cnt=0;
    memset(lz,0,sizeof(lz));
    scanf("%d%d%d%d",&p,&q,&l,&r);
    for (int i=0;i<p;i++) 
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for (int j=a;j<=b;j++) lz[j]=true;
    }
    for (int i=0;i<q;i++) scanf("%d%d",&xyz[i].c,&xyz[i].d);
    for (int i=l;i<=r;i++)
    {
        for (int j=0;j<q;j++)
        {
            bool flag=false;
            int c=xyz[j].c+i,d=xyz[j].d+i;
            for (int k=c;k<=d;k++)
              if (k>1000) break;
              else if (lz[k]) 
              {
                flag=true;
                cnt++;
                break;
              }
            if (flag) break;
        }
    }
    printf("%d",cnt);
    return 0;
}