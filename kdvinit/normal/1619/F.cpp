/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int l = n/m;
    int e = (n%m);


    int lst=0;
    while(k--)
    {
        int cnt=lst;
        for(int i=1; i<=e; i++)
        {
            cout<<l+1<<" ";
            for(int j=1; j<=l+1; j++)
            {
                cnt = (cnt%n)+1;
                cout<<cnt<<" ";
            }
            cout<<endl;
        }
        lst=cnt;

        for(int i=e+1; i<=m; i++)
        {
            cout<<l<<" ";
            for(int j=1; j<=l; j++)
            {
                cnt = (cnt%n)+1;
                cout<<cnt<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}