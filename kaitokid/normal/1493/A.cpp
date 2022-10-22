#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{   ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int r=(k+1)/2;
        cout<<n-r<<endl;
        for(int i=r;i<=n;i++)if(i!=k)cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}