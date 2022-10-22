#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,m,x;
    cin>>n>>m;
for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
{
    cin>>x;
    if((x%2)==((i+j)%2))cout<<x<<" ";
    else cout<<x+1<<" ";
}
cout<<"\n";

    }
}
    return 0;
}