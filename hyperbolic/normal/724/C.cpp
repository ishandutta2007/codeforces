#include <stdio.h>
struct str{
    int x0;
    int y0;
}A[400010];
long long int gcd(long long int a, long long int b)
{
    return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
    return (a/gcd(a,b))*b;
}
long long int ans[100010];
int x[200010],y[200010];
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=c;i++) ans[i] = -1;
    for(int i=1;i<=c;i++) scanf("%d%d",&A[i].x0,&A[i].y0);
    if(a==b)
    {
        for(int i=1;i<=c;i++)
        {
            if(A[i].x0==A[i].y0) printf("%d\n",A[i].x0);
            else printf("-1\n");
        }
        return 0;
    }
    for(int i=1;i<=c;i++)
    {
        A[c+i].x0 = 2*a-A[i].x0;
        A[c+i].y0 = A[i].y0;
    }
    for(int i=1;i<=c;i++)
    {
        A[2*c+i].x0 = A[i].x0;
        A[2*c+i].y0 = 2*b-A[i].y0;
    }
    for(int i=1;i<=c;i++)
    {
        A[3*c+i].x0 = 2*a-A[i].x0;
        A[3*c+i].y0 = 2*b-A[i].y0;
    }

    for(int i=0;i<=2*a;i++) x[i] = -1;
    for(int i=0;i<=2*b;i++) y[i] = -1;
    for(int i=0;i<=2*a;i++) if(x[((long long int)2*b*i)%(2*a)]==-1) x[((long long int)2*b*i)%(2*a)] = i;
    for(int i=0;i<=2*b;i++) if(y[((long long int)2*a*i)%(2*b)]==-1) y[((long long int)2*a*i)%(2*b)] = i;
    for(int i=1;i<=4*c;i++)
    {
        //A[i].x0 + k1*2a == A[i].y0 + k2*2b
        // k1(2a) +x-y = k2(2b)
        // k1(2a) = k2(2b) + y-x
        int x1 = A[i].x0;
        int y1 = A[i].y0;
        long long int s;
        if(x1>=y1) s = y[(2*b-(x1-y1)%(2*b))%(2*b)];
        else s = y[(y1-x1)%(2*b)];
        if(s==-1) continue;
        long long int t = (s*2*a+x1-y1)/(2*b);
        while(t<0) s+=lcm(a,b),t+=lcm(a,b);
        s%=(b/gcd(a,b));
        t%=(a/gcd(a,b));

        if(ans[(i-1)%c+1]==-1) ans[(i-1)%c+1] = s*2*a+x1;
        else ans[(i-1)%c+1] = ans[(i-1)%c+1]<s*2*a+x1?ans[(i-1)%c+1]:s*2*a+x1;
    }
    for(int i=1;i<=c;i++)
    {
        printf("%I64d\n",ans[i]);
    }
}