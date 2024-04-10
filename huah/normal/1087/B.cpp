#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=1e9;
    for(int i=1;i<=n;i++)
        if(n%i==0)
        {
            for(int x=i*k;x<i*k+k;x++)
            if(x%k*i==n) {ans=min(ans,x);break;}
        }
    printf("%d\n",ans);
}