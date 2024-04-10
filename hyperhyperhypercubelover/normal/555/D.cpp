#include<cstdio>
#include<algorithm>

int a[222222];
std::pair<int,int> b[222222];
int c[222222];

int main()
{
    int temp;
    int i,j,n,m,t,dir;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i].first=a[i];
        b[i].second=i;
    }
    std::sort(b,b+n);
    for(i=0;i<n;i++)
    {
        a[i]=b[i].first;
        c[b[i].second]=i;
    }
    while(m--)
    {
        scanf("%d%d",&i,&j);
        i--;
        i=c[i];
        t=std::upper_bound(a,a+n,a[i]+j)-a-1;
        j-=a[t]-a[i];
        i=t;
        t=std::lower_bound(a,a+n,a[i]-j)-a;
        j-=a[i]-a[t];
        i=t;
        dir=0;
        for(temp=80;temp;temp--)
        {
            if(dir==0)
            {
                t=std::upper_bound(a,a+n,a[i]+j)-a-1;
                if(t==i)break;
                else
                {
                    if(j/(a[t]-a[i])%2)dir=1;
                    j%=a[t]-a[i];
                    if(dir)i=t;
                }
            }
            else
            {
                t=std::lower_bound(a,a+n,a[i]-j)-a;
                if(t==i)break;
                else
                {
                    if(j/(a[i]-a[t])%2)dir=0;
                    j%=a[i]-a[t];
                    if(!dir)i=t;
                }
            }
        }
        printf("%d\n",b[i].second+1);
    }
}