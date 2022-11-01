#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,z,b[N],a[N];
long long sum=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        b[i]=x;
        if(abs(b[i]-x)<1e-8) a[i]=2;
        else if(x<0) a[i]=1;
        else if(x>0) a[i]=0;
        sum+=b[i];
    }
    if(sum<0)
    {
        sum=-sum;
        for(int i=1;i<=n&&sum;i++)
            if(a[i]==0)
            {
                sum--;
                b[i]++;
            }
    }
    else
    {
        for(int i=1;i<=n&&sum;i++)
            if(a[i]==1)
        {
            sum--;
            b[i]--;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",b[i]);
}