// Hydro submission #631f2dbb32ae6c3198c90bf2@1662987707990
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;k%=4;
        if(!k) printf("NO\n");
        else
        {
            printf("YES\n");
            if(k%2) for(i=2;i<=n;i+=2)
            printf("%d %d\n",i-1,i);
            else if(k) for(i=2;i<=n;i+=2)
            if(i/2%2) printf("%d %d\n",i,i-1);
            else printf("%d %d\n",i-1,i);
        }
    }
    return 0;
}