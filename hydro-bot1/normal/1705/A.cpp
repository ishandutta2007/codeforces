// Hydro submission #62d7a7cf9ef728749e1e0cd1@1658300368458
#include<bits/stdc++.h>
using namespace std;
int h[200];
int main()
{
    int t,n,x,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(i=0;i<n*2;i++)
        cin>>h[i];
        sort(h,h+n*2);
        for(i=0;i<n;i++)
        if(h[i+n]-h[i]<x)
        {
            printf("NO\n");
            goto end;
        }
        printf("YES\n");
        end:;
    }
    return 0;
}