#include <bits/stdc++.h>

using namespace std;
int x,n,m;
bool f[600009];
bool th[31][600009];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=0;i<n;i++){cin>>x;f[x]=true;}
for(int i=0;i<600000;i++)
{
    if(f[i])continue;
    int q=i;
    for(int j=0;j<21;j++){th[j][q]=true;q/=2;}
}
int u=0;
for(int i=0;i<m;i++)
{
    cin>>x;
    u^=x;
    if(!f[u]){cout<<"0\n";continue;}
    int ans=0;
    for(int j=20;j>=0;j--)
        {
        ans*=2;
    if(!th[j][((u>>j)^ans)])
    ans+=1;


        }
cout<<ans<<"\n";
}
    return 0;
}