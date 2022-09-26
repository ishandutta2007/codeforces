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
    int n, k;
    cin>>n>>k;
    int i=0;
    int s=0;
    while (true)
    {
        i++;
        s+=i;
        if (s>=k)
            break;
    }
    int x, y;
    x=n-i;
    y=n+x-(n-s+k)+1;
    for (int i=1; i<=n; i++)
        if ((i!=x) and (i!=y))
        cout<<"a";
    else
        cout<<"b";
    cout<<"\n";
    }
}