#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(a[i]==1) ans++;
    printf("%.20f\n",(double)s/ans*2);
}