#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
//#define int ll

using namespace std;

const int nmax = 100500;

int n;
int a[nmax];

int cntx(int l, int r)
{
    int val = a[r];
    int res = 0;
    for (int i=r-1; i>=l; i--)
    {
        int k = (a[i] + val - 1) / val;
        res += k-1;
        val = a[i] / k;
    }
    /// val -> 2*sqrt different values (k=1, ..., sqrt, val = 1, 2, ..., sqrt)
    return res;
}

int cnt[2][nmax];
int sz[2];
int nz[2][nmax];

ll supercnt()
{
    int ii = 0;

    ll res = 0;
//    unordered_map<int, int> vals;
    for (int i=n; i>=1; i--)
    {
        cnt[ii][100000]++;
        nz[ii][sz[ii]++] = 100000;

        sz[ii^1] = 0;

        for (int j=0; j<sz[ii]; j++)
        {
            int val = nz[ii][j];
            if (cnt[ii][val] == 0)
                continue;
            int c = cnt[ii][val];

            int k = (a[i] + val - 1) / val;
            res += ll(c) * (k-1) * i;
            res %= 998244353;

            cnt[ii][val] = 0;

            cnt[ii^1][a[i] / k] += c;
            nz[ii^1][sz[ii^1]++] = a[i]/k;
        }

//        unordered_map<int, int> new_vals;
//        vals[1e5]++;
//        for (auto [val, c] : vals)
//        {
//            int k = (a[i] + val - 1) / val;
//            res += c * (k-1) * i;
//            res %= 998244353;
//
//            new_vals[a[i] / k] += c;
//        }
//        vals = new_vals;

        ii^=1;
    }

    for (int j=0; j<sz[ii]; j++)
        cnt[ii][nz[ii][j]]=0;
    sz[0] = sz[1] = 0;

    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
//            a[i] = rand()%10 + 1;
        }

//        int ans=0;
//        for (int l=1; l<=n; l++)
//            for (int r=1; r<=n; r++)
//                ans+=cntx(l, r);
//        cout<<ans<<"\n";

        cout<<supercnt()<<"\n";
    }
}