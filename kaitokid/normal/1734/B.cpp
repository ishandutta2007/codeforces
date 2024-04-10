#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<1<<endl;
        for(int i=2;i<=n;i++)
        {
            cout<<1<<" ";
            for(int j=0;j<i-2;j++)cout<<0<<" ";
            cout<<1<<endl;
        }
    }
    return 0;
}