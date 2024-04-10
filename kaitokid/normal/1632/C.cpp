#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int go(int x,int y)
{
    int u=-1;
    int r=(y|x)-y;
    for(int i=23;i>=0;i--)
    if(r&(1<<i)){u=i;break;}
    // cout<<x<<" "<<y<<" "<<u<<endl;
    if(u==-1)return 0;

    int p=y;
    for(int i=0;i<=u;i++)if(p&(1<<i))p-=(1<<i);
    p|=x;
    return p-y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=b-a;
        for(int i=a;i<b;i++)
            ans=min(ans,i-a+go(i,b)+1);
        cout<<ans<<endl;
    }
    return 0;
}