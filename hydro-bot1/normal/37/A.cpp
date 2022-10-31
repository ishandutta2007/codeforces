// Hydro submission #6247f67c993deab656107671@1648883324730
#include<bits/stdc++.h>
using namespace std;
int s[1000],m,mx,ss;
int main()
{
    int l,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l;
        if(l>m)
        m=l;
        s[l]++;
    }
    for(i=0;i<=m;i++)
    {
        if(s[i]) ss++;
        if(s[i]>mx)
        mx=s[i];
    }
    printf("%d %d\n",mx,ss);
    return 0;
}