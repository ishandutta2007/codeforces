#include <stdio.h>
#include <string.h>
int min,max;
int P,M,value;
int p[110];
int m[110];
char x[10010];
int main()
{
    int a,i,j;
    fgets(x+1,10000,stdin);
    a = strlen(x+1);
    a--;
    for(i=1;i<=a;i++)
    {
        if(x[i]=='+') P++;
        if(x[i]=='-') M++;
        if(x[i]=='=') break;
    }
    for(i+=2;i<=a;i++)
    {
        value*=10;
        value+=(x[i]-'0');
    }
    P++;
    if(P-M*value<=value&&value<=P*value-M)
    {
        printf("Possible\n");
        int thisValue = P-M,s=1,t=1;
        for(i=1;i<=P;i++) p[i]=1;
        for(i=1;i<=M;i++) m[i]=1;
        while(thisValue!=value)
        {
            if(thisValue<value)
            {
                int s0 = value-p[s];
                if(value-p[s]>=value-thisValue)
                {
                    p[s]+=value-thisValue;
                    thisValue = value;
                }
                else
                {
                    thisValue += value-p[s];
                    p[s] = value;
                    s++;
                }
            }
            else
            {
                int s0 = value-m[t];
                if(value-m[t]>=thisValue-value)
                {
                    m[t]+=thisValue-value;
                    thisValue = value;
                }
                else
                {
                    thisValue -= value-m[t];
                    m[t] = value;
                    t++;
                }
            }
        }

        int s2=1,t2=1,control = 1;
        for(i=1;i<=a;i++)
        {
            if(x[i]=='?')
            {
                if(control==1) printf("%d",p[s2++]);
                if(control==2) printf("%d",m[t2++]);
            }
            else
            {
                printf("%c",x[i]);
                if(x[i]=='-') control = 2;
                if(x[i]=='+') control = 1;
            }
        }
    }
    else printf("Impossible");
}