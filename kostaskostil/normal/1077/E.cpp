#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
map<int, int> m;
int x;
vector<int> v;

int nt(int l, int r, int x)
{
    if (r==l)
        return l;
    if (v[(l+r)/2]>=x)
        return nt(l, (l+r)/2, x);
    return nt((l+r)/2 +1, r, x);
}

int ans(int q)
{
    int answ=0;
    int i=nt(0, n, q);
    while (true)
    {
        if (i>=n)
            return answ;
        answ+=q;
        q*=2;
        i=nt(i+1, n, q);
    }
}

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x, m[x]++;
    for (auto pa:m)
        v.pb(pa.se);
    n=v.size();
    sort(v.begin(), v.end());

//    for (auto i:v)
//        cout<<i<<" ";
//    cout<<"\n";
//    for (int i=1; i<=n; i++)
//        cout<<ans(i)<<" ";

    int answ=0;
    for (int i=1; i<=v[n-1]; i++)
        answ=max(answ, ans(i));
    cout<<answ<<"\n";
    return 0;
}