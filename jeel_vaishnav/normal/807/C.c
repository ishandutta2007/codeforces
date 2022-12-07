#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
    {
int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        {
        long long int x,y,p,q;
        scanf("%I64d%I64d%I64d%I64d",&x,&y,&p,&q);
        long long int perm=x,perm1=y;
        if((q==p&&x!=y)||(x>0&&p==0))
            printf("-1\n");
        else if((q==p&&x==y)||(x==0&&p==0))
            printf("0\n");
        else
            {
        if(y%q!=0)
            y=(y/q+1)*q;
        x=y/q*p;//settle
        if(x<perm)
            {
            if((perm-x)%p==0)
                {
                 y+=(perm-x)/p*q;
                x=perm;               
            }
            else{
                   y+=((perm-x)/p+1)*q;
                x+=((perm-x)/p+1)*p;             
            }
        }//settle x
            //printf("%d %d\n",x,y);
        if(y-perm1<x-perm)
            {
            long long int step=(x-perm-y+perm1),time;
            if(step%(q-p)==0&&q-p!=0)
                time=step/(q-p);
            else
                time=step/(q-p)+1;
            x+=p*time;
            y+=q*time;
        }//settle diff
        printf("%I64d\n",y-perm1);
        }
    }
    return 0;
}