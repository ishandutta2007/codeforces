#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
int t,n;
ll x,a,b;
cin>>t;
while(t--)
{
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cout<<char('a'+i%b);
    cout<<endl;
}
    return 0;
}