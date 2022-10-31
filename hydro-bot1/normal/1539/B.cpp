// Hydro submission #6274d62bbda16328ffbb021e@1651824171748
#include<bits/stdc++.h>
using namespace std;
int m[100001];
int main()
{
    int n,t,l,r,i,j;
    cin>>n>>t;
    string s;
    cin>>s;
    for(i=1;i<=n;i++)
    m[i]=m[i-1]+s[i-1]-96;
    for(i=0;i<t;i++)
    {
        cin>>l>>r;
        printf("%d\n",m[r]-m[l-1]);
    }
    return 0;
}