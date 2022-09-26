#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;

const __int128 MOD=1e9+7;

void read(__int128&x)
{
    ll y;
    cin>>y;
    x=y;
}

void write(__int128 x)
{
    ll y=x%MOD;
    cout<<y<<"\n";
}

#define int __int128

int f(int m)
{
    int k=m/4 + 1;

    return k*(m/2 + 1) - k*(k-1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    read(n);
    for (int x, i=0; i<n; i++)
    {
        read(x);
        write(f(x));
    }
    return 0;
}