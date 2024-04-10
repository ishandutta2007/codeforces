#include<stdio.h>
int sgtreea[26][524299],sgtreeb[26][524299],i,j,k,trsize,n,m;
char a[222222],b[222222];
int sgsa(int qwe,int s,int e)
{
    s+=trsize;
    e+=trsize;
    int ans=0;
    while(s<=e)
    {
        if(s%2==1)
        {
            ans+=sgtreea[qwe][s];
            s++;
        }
        if(e%2==0)
        {
            ans+=sgtreea[qwe][e];
            e--;
        }
        s/=2;
        e/=2;
    }
    return ans;
}
int sgsb(int qwe,int s,int e)
{
    s+=trsize;
    e+=trsize;
    int ans=0;
    while(s<=e)
    {
        if(s%2==1)
        {
            ans+=sgtreeb[qwe][s];
            s++;
        }
        if(e%2==0)
        {
            ans+=sgtreeb[qwe][e];
            e--;
        }
        s/=2;
        e/=2;
    }
    return ans;
}
int f(int as,int bs,int m)
{
    if(m%2){for(int i=0;i<m;i++)if(a[as+i]!=b[bs+i])return 0;return 1;}
    for(int i=0;i<26;i++)if(sgsa(i,as,as+m-1)!=sgsb(i,bs,bs+m-1))return 0;
    return (f(as,bs,m/2)&&f(as+m/2,bs+m/2,m/2)) || (f(as,bs+m/2,m/2)&&f(as+m/2,bs,m/2));
}
int main()
{
    scanf("%s%s",a,b);
    for(;a[++n];);
    for(trsize=1;trsize<n;trsize*=2);
    for(i=0;i<26;i++)
    {
        for(j=0;j<n;j++)
        {
            k=j+trsize;
            while(k)
            {
                if(a[j]-'a'==i)sgtreea[i][k]++;
                k/=2;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<n;j++)
        {
            k=j+trsize;
            while(k)
            {
                if(b[j]-'a'==i)sgtreeb[i][k]++;
                k/=2;
            }
        }
    }
    printf("%s",f(0,0,n)?"YES":"NO");
}