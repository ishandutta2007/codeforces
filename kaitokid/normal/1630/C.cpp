#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int lst[200009];
int a[200009];
int b[200009];
int d[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=lst[a[i]];
       d[i]=i;
       if(b[i-1]>b[i]){b[i]=b[i-1];d[i]=d[i-1];}
    }
    int l=0;
    int i=1,ans=0;
    while(i<n)
    {
        if(b[i]==i){i++;l=i;continue;}
        int u=b[i];
        if(b[u]==u){ans+=b[i]-max(i,l)-1;i=b[i]+1;continue;}
        ans+=b[i]-max(i,l)-2;
        l=b[i]-1;
        i=d[u];
    }
    cout<<ans;

    return 0;
}