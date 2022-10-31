// Hydro submission #6267792e255d14008c299bf4@1650948399326
#include<bits/stdc++.h>
using namespace std;
string s[21],t[21];
int main()
{
    int n,m,i,q,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>s[i];
    for(i=1;i<=m;i++)
    cin>>t[i];
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>y;
        cout<<s[y%n?y%n:n]<<t[y%m?y%m:m]<<endl;
    }
    return 0;
}