#include<stdio.h>
#include<algorithm>
int a,n,startp[1000100],endp[1000100],beauty[1000100],maxbeauty,i,ansstart,ansend;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=1000010;i++)startp[i]=987654321;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        startp[a]=std::min(startp[a],i);
        endp[a]=std::max(endp[a],i);
        beauty[a]++;
    }
    for(i=1;i<=1000010;i++)maxbeauty=std::max(maxbeauty,beauty[i]);
    ansstart=1;
    ansend=987654321;
    for(i=1;i<=1000010;i++)
    {
        if(beauty[i]==maxbeauty)
        {
            if(endp[i]-startp[i]<ansend-ansstart)
                ansend=endp[i],
                ansstart=startp[i];
        }
    }
    printf("%d %d",ansstart,ansend);
}