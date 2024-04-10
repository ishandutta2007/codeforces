// Hydro submission #629876571008115bd64c909d@1654158935807
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
    int t,n,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n;s=0;
        for(i=0;i<n;i++)
        cin>>a[i],s+=a[i];
        if(s%n) printf("NO\n");
        else
        {
            s/=n;
            for(i=0;i<n;i++)
            if(a[i]==s)
            {
                printf("YES\n");
                goto next;
            }
            printf("NO\n");next:;
        }
    }
    return 0;
}