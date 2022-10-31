// Hydro submission #62d49e2db36e4a12382db4a1@1658101294021
#include<bits/stdc++.h>
using namespace std;
bool a[1001],b[1001];
int main()
{
    int n,s,i;
    cin>>n>>s;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<=n;i++)
    cin>>b[i];
    if(!a[1])
    {
        printf("NO\n");
        return 0;
    }
    if(a[s])
    {
        printf("YES\n");
        return 0;
    }
    if(!b[s])
    {
        printf("NO\n");
        return 0;
    }
    for(i=s+1;i<=n;i++)
    if(a[i]==b[i]&&a[i])
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}