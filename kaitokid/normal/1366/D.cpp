#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ls[10000009];
int fr[10000009];
int a[500009],b[500008];
int main()
{
    ios::sync_with_stdio(0);
    for(int i=2;i<10000000;i++)
    {
        if(fr[i]!=0)continue;
        for(int j=i;j<=10000000;j+=i){ls[j]=i;if(fr[j]==0)fr[j]=i;}
    }
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i]=-1;
        b[i]=-1;
//cout<<fr[x]<<endl;
if(ls[x]==fr[x])continue;
int u=fr[x];
while(x%u==0)x/=u;

a[i]=u;
b[i]=x;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<b[i]<<" ";
    return 0;
}