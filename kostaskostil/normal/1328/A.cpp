#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=100500;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int j=1; j<=t; j++)
    {

    int a, b;
    cin>>a>>b;
    if (a%b==0)
        cout<<0<<"\n";
    else
        cout<<b-(a%b)<<"\n";
    }
}