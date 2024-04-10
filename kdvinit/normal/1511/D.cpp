/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    vector<char> Cyc;
    for(int i=1; i<=k; i++)
    {
        Cyc.push_back('a'-1+i);
        for(int j=i+1; j<=k; j++)
        {
            Cyc.push_back('a'-1+i);
            Cyc.push_back('a'-1+j);
        }
    }

    int m=Cyc.size();
    for(int i=0; i<n; i++)
    {
        cout<<Cyc[i%m];
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}