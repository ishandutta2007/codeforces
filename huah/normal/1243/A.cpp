#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,min(a[i],n-i+1));
        printf("%d\n",ans);
    }
}