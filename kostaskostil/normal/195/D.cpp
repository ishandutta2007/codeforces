#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int k[100500];
int b[100500];
vector<double> v;
int n;

map<pair<int, int>, int> m;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>k[i]>>b[i];
        int t=__gcd(abs(k[i]), abs(b[i]));
        if (k[i]==0)
        {
            i--;
            n--;
            continue;
        }
        if (b[i]==0)
            t=k[i];
        if (b[i]>0)
            t=-t;
        m[{-b[i]/t, k[i]/t}]+=abs(k[i]);
    }
    int ans=0;
    for (auto pa:m)
        if (pa.se!=0)
            ans++;
    cout<<ans<<"\n";
}