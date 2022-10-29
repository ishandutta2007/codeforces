/**************************************************************
    File name: 1183F.cpp
    Author: huhao
    Email: 826538400@qq.com
    Create time: 2019/6/26 11:01:08
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
    int r=0,t=1,c=getchar();
    while(c<'0'||c>'9')
    
    {
        t=c=='-'?-1:1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        r=(r<<3)+(r<<1)+(c^48);
        c=getchar();
    }
    return r*t;
}
const int N=200010;
int q,n,a[N],p[N];
int main()
{
    q=read();
    while(q--)
    {
        n=read();
        fr(i,1,n)
        {
            a[i]=read();
            p[a[i]]=1;
        }
        sort(a+1,a+n+1);
        int ans=0;
        if(a[n]%30==0&&p[a[n]/2]&&p[a[n]/3]&&p[a[n]/5])
            ans=a[n]/30*31;
        int k=a[n],s=0;
        fd(i,n-1,1)
            if(a[n]%a[i]!=0&&(s==0||s%a[i]!=0))
            {
                k+=a[i];
                if(s==0)
                    s=a[i];
                else
                    break;
            }
        printf("%d\n",max(ans,k));
    }
    return 0;
}