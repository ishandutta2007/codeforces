// Hydro submission #6291d5a737e0de7afd3ad25f@1653724584520
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int t,n,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n;s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0) s++;
        }
        for(i=0;i<s;i++)
        {
            a[i]=-abs(a[i]);
            if(i&&a[i]<a[i-1])
            {
                printf("NO\n");
                goto next;
            }
        }
        for(i=s;i<n;i++)
        {
            a[i]=abs(a[i]);
            if(i-s&&a[i]<a[i-1])
            {
                printf("NO\n");
                goto next;
            }
        }
        printf("YES\n");
        next:;
        
    }
    return 0;
}