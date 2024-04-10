#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

    int n;
    cin>>n;
    cout<<2<<endl;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        for(int j=i;j<=n;j*=2){cout<<j<<" ";vis[j]=true;}
    }
    cout<<endl;
        }

    return 0;
}