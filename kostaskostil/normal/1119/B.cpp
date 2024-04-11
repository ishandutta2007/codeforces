#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n, h;
int a[300500];

multiset<int> s;

bool ch()
{
    int a,b;
    int c=0;
    int h0=0;
    for (auto i=prev(s.end()); i!=prev(s.begin()); i--)
    {
        if (c==0)
            a=*i, c=1;
        else
        {
            b=*i;
            c=0;
            h0+=max(a, b);
        }
    }
    if (c==1)
        h0+=a;
    return (h0<=h);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        s.insert(a[i]);
        if (!ch())
            cout<<i-1<<"\n", exit(0);
    }
    cout<<n<<"\n";
    return 0;
}