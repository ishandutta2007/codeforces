#include <iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

long long ans,n,a[2000000],b[2000000],c[2000000],t1[40],t2[40],q,x,f,w;

void m(long long r,long long y)
{
    long long l=r-(1<<y)+1;
    if(y==0)
        return;
   // cout<<"*"<<l<<" "<<r<<endl;
    long long mid=r-(1<<(y-1))+1;
    m(r,y-1);m(mid-1,y-1);
    for(long long i=l;i<mid;i++)
        b[i-l]=a[i];
    for(long long i=mid;i<=r;i++)
        c[i-mid]=a[i];
    long long p=0,q=0;
    while(p<mid-l && q<r-mid+1)
    {
        //if(b[p]==c[q])
        if(b[p]>c[q])
        {
            ans+=mid-l-p;
            t2[y]+=mid-l-p;
         //   cout<<l<<" "<<r<<" "<<p<<" "<<q<<endl;
            a[l+p+q]=c[q];
            q++;
        }
        else
        {
            a[l+p+q]=b[p];
            w=upper_bound(c,c+r-mid+1,b[p])-c;
            p++;
            t1[y]+=r-mid+1-w;
          //  cout<<y<<" "<<t1[y]<<endl;;
        }
    }
    if(p==mid-l)
        for(long long i=q;i<r-mid;i++)
            a[l+p+i]=c[i];
    else
        for(long long i=p;i<mid-l;i++)
            a[l+i+q]=b[i];
}

int main()
{
    scanf("%lld",&n);
    for(long long i=1;i<=(1<<n);i++)
        scanf("%lld",&a[i]);
    m((1<<n),n);
    scanf("%lld",&q);
  //  for(long long i=0;i<=n;i++)
    //    cout<<t1[i]<<" "<<t2[i]<<endl;
    for(long long qw=0;qw<q;qw++)
    {
        scanf("%lld",&x);
        for(long long i=0;i<=x;i++)
        {
            ans+=t1[i]-t2[i];
            swap(t1[i],t2[i]);
        }
        printf("%lld\n",ans);
    }
}