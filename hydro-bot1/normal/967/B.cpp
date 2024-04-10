// Hydro submission #6259213ecc64917dc46654c8@1650008398027
#include<bits/stdc++.h>
using namespace std;
int s[100000];
long long t;
int main()
{
    int n,a,b,i;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
    cin>>s[i],t+=s[i];
    sort(s+1,s+n);
    if(a*s[0]>=b*t)
    {
        printf("0\n");
        return 0;
    }
    for(i=n-1;i>0;i--)
    {
        t-=s[i];
        if(a*s[0]>=b*t)
        {
            printf("%d\n",n-i);
            return 0;
        }
    }
    return 0;
}