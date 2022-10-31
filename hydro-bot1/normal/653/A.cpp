// Hydro submission #62550b6f17cd4d0a41764b2e@1649740657530
#include<bits/stdc++.h>
using namespace std;
int t[50],p[50],s;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>t[i];
    sort(t,t+n);
    p[0]=t[0];
    for(i=1;i<n;i++)
    if(t[i]-t[i-1])
    s++,p[s]=t[i];
    for(i=2;i<=s;i++)
    if(p[i]-p[i-1]==1
    &&p[i]-p[i-2]==2)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}