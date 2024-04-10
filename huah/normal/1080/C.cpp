#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f1[10],f2[10];
int  main()
{
    ll t,i,j,n,m,aa,bb,a,b,xx,x,yy,y,l,r,p,q,pp,qq,z,zz,e1,e2;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        r=(n*m)/2;
        l=(n*m)-r;
        scanf("%lld%lld%lld%lld",&y,&x,&yy,&xx);
        f1[0]=x;
        f1[1]=xx;
        f2[0]=y;
        f2[1]=yy;
        if((x+y)%2)
        {
            a=(yy-y+1)*(xx-x+1)/2;
            b=(yy-y+1)*(xx-x+1)-a;
        }
        else
        {
            b=(yy-y+1)*(xx-x+1)/2;
            a=(yy-y+1)*(xx-x+1)-a;
        }
        l=l+b;
        r=r-b;
        scanf("%lld%lld%lld%lld",&b,&a,&bb,&aa);
        f1[2]=a;
        f1[3]=aa;
        f2[2]=b;
        f2[3]=bb;
        sort(f1,f1+4);
        sort(f2,f2+4);
        e1=f1[1];
        e2=f2[1];
        if(e1<=xx&&e1>=x&&e2<=yy&&e2>=y&&e1<=aa&&e1>=a&&e2<=bb&&e2>=b)
        {
            p=f1[1];
            q=f2[1];
            pp=f1[2];
            qq=f2[2];
            if((p+q)%2)
            {
                z=(pp-p+1)*(qq-q+1)/2;///
                zz=(pp-p+1)*(qq-q+1)-z;///
            }
            else
            {
                zz=(pp-p+1)*(qq-q+1)/2;
                z=(pp-p+1)*(qq-q+1)-zz;
            }
            r+=zz;
            l-=zz;
        }
        if((a+b)%2)
        {
            p=(aa-a+1)*(bb-b+1)/2;
            q=(aa-a+1)*(bb-b+1)-p;
        }
        else
        {
            q=(aa-a+1)*(bb-b+1)/2;
            p=(aa-a+1)*(bb-b+1)-q;
        }
        l-=p;
        r+=p;
        printf("%lld %lld\n",l,r);
 
    }
}