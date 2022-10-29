#include <iostream>

using namespace std;
long long hcf(long long a, long long b)
{
   if(b==0) return a;
   if(a>b) return(hcf(b,a%b));
   else  return(hcf(a,b%a));
}
void lcm(long long &a,long long b)
{
   a=(a*b)/hcf(a,b);
}
int main()
{
    long long n,a[101],i,p,j;
    long long t,tt=1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;++i)
    {  p=i;
        for(j=1;j<=2*(n+1);++j)
            if(a[p]==i) break;
            else p=a[p];
         if(j==2*n+3) {tt=-1;break;}
         else if(j%2==0) t=j/2;
         else t=j;
       if(t!=0)lcm(tt,t);
      // cout<<tt;
    }
    cout<<tt;
    return 0;
}