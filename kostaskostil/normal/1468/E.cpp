#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 1e5+100;

typedef long long ll;
#define int ll

int get(int a, int b, int c, int d)
{
    return min(a, b) * min(c, d);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    int a, b, c, d;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin>>a>>b>>c>>d;
        int mx = 0;
        mx = max(mx, get(a, b, c, d));
        mx = max(mx, get(a, c, b, d));
        mx = max(mx, get(a, d, b, c));
        cout<<mx<<"\n";
    }
}