#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{

    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
int u=(n+3)/4;
for(int i=0;i<n-u;i++)cout<<9;
for(int i=0;i<u;i++)cout<<8;
cout<<endl;
}
    return 0;
}