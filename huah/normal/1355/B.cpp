#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0,tot=0;
        for(int i=1;i<=n;i++)
        {
            tot++;
            if(tot>=a[i]) ans++,tot=0;
        }
        printf("%d\n",ans);
    }
}