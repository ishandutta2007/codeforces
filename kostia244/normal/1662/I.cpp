#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int p[500500];
int n, m;
const int D = 1e8;
const int T = 100;
int len(int x)
{
    if (x<0) return 0;
    if (x>=n) return p[n-1];
    return p[x];
}

int get(int l, int r)
{
    if (r <= l)
        return 0;

    int ans = 0;
    int lx = (l/T + 1);
    int rx = (r-1)/T;

    for (int i = lx; i <= rx; i++)
    {
        int pos = 2*T*i - l - 1;
        pos = min(pos, r-1);
        int rpos = (pos + r) / 2;
        int rdist = min(rx, rpos / T);

//        cout<<l<<" "<<r<<" "<<i<<" "<<pos<<" "<<rpos<<" "<<rdist<<" "<<len(rdist - D/T) - len(i - D/T - 1)<<"\n";
        ans = max(ans, len(rdist - D/T) - len(i - D/T - 1));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>p[i];
    for (int i=1; i<n; i++)
        p[i]+=p[i-1];

    vector<int> v(m+2);
    v[0] = 0;
    for (int i=1; i<=m; i++)
    {
        cin>>v[i];
        v[i] = min(v[i], D);
        v[i]+=D;
    }
    v[m+1] = 2*D;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i=0; i<=m; i++)
        ans = max(ans, get(v[i], v[i+1]));
    cout<<ans<<"\n";
}