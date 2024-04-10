#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,k,m;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int mx=min(n/k,m);
        int mn=(m-mx+k-2)/(k-1);
        cout<<mx-mn<<endl;
    }
    return 0;
}