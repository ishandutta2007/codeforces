#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int s=0;
        for(int i=0;i<n;i++){cin>>x;s+=x;}
        if(s==m)cout<<"YES\n";
        else cout<<"NO\n";
    }
return 0;
}