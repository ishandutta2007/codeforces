#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
int Q(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
int a[N];
int A(int x)
{
    if(a[x]) return a[x];
    return a[x]=Q(x);
}
bool judge(int x)
{
    if(x-1>=1&&A(x-1)<A(x)) return false;
    if(x+1<=n&&A(x+1)<A(x)) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    int l=1,r=n,ans;
    while(r-l>5)
    {
        int m=l+r>>1;
        if(A(m)<A(m-1)) l=m;
        else r=m-1;
    }
    for(int i=l;i<=r;i++)
        if(judge(i))
    {
        printf("! %d\n",i);break;
    }
}