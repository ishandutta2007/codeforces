#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,x,s=0;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>x;
        s+=(x%2);
    }
    if(s==n)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}