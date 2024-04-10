#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool c[55],r[55];
int main()
{
ios::sync_with_stdio(0);
int n,m,t;
cin>>t;
while(t--)
{
cin>>n>>m;
for(int i=0;i<n;i++)c[i]=false;
for(int i=0;i<m;i++)r[i]=false;
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
{
int x;
    cin>>x;
    if(x==1){c[i]=true;r[j]=true;}

}
int u=0,v=0;
for(int i=0;i<n;i++)if(!c[i])u++;
for(int i=0;i<m;i++)if(!r[i])v++;
u=min(u,v);
if(u%2)cout<<"Ashish\n";
else cout<<"Vivek\n";

    }
    return 0;
}