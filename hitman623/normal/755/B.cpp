#include <bits/stdc++.h>

using namespace std;

int main()
{
    map <string , long > q;
    long n,m,u,inter,i;
    char a[1000][505],b[1000][505];
    cin>>n>>m;
    for(i=0;i<n;++i)
        {cin>>a[i];q[a[i]]=1;}
    for(i=0;i<m;++i)
        {cin>>b[i];q[b[i]]=1;}
    u=q.size();
    //cout<<u;
    inter=n+m-u;
    n+=(inter+1)/2;
    m+=inter/2;
    if(n>m) cout<<"YES";
    else cout<<"NO";
    return 0;
}