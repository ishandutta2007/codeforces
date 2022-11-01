#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,k,a[N];
bool solve()
{
    bool flag=false;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),flag|=a[i]==k;
    if(!flag) return false;
    if(n==1) return true;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n&&j<=i+2;j++)
        if(a[i]>=k&&a[j]>=k) return true;
    return false;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf(solve()?"yes\n":"no\n");
    }
}