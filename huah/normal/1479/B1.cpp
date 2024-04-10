#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,a[N];
int m,c[N],s[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int t=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
            t++;
        else
        {
            m++;c[m]=a[i-1];s[m]=t;
            t=1;
        }
    }
    m++;c[m]=a[n];s[m]=t;
    int ans=0,c1=-1,c2=-1;
    c[m+1]=-4;
    for(int i=1;i<=m;i++)
        if(s[i]>=2)
        {
            ans+=c1!=c[i];
            ans+=c2!=c[i];
            c1=c2=c[i];
        }
        else
        {
            if(c1!=c[i]&&c2!=c[i])
            {
                ans++;
                if(c1==c2) c1=c[i];
                else
                {
                    if(c2==c[i+1]) c2=c[i];
                    else c1=c[i];
                }
            }
            else if(c1!=c[i])
            {
                ans++;c1=c[i];
            }
            else if(c2!=c[i])
            {
                ans++;c2=c[i];
            }
            else c1=c[i];
        }
    printf("%d\n",ans);
}