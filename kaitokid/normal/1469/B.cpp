#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t,n,m;

cin>>t;
while(t--)
{
    cin>>n;
    int s=0,mx1=0,x;
    for(int i=0;i<n;i++ )
    {
        cin>>x;
        s+=x;
        mx1=max(mx1,s);
    }
    s=0;
    cin>>m;
    int mx2=0;
    for(int i=0;i<m;i++ )
    {
        cin>>x;
        s+=x;
        mx2=max(mx2,s);
    }
    cout<<mx1+mx2<<endl;
}
    return 0;
}