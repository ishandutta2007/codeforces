#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

//typedef long long ll;
//#define int ll

using namespace std;

int n, k;
bool a[200500][65];
int cnt[65];
int masks[200500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int p;
    cin>>n>>k>>p;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<k; j++)
            a[i][j] = (s[j]=='1');
    }
    for (int i=1; i<=n; i++)
        for (int j=0; j<k; j++)
            if (a[i][j])
                cnt[j]++;
    pair<int, string> mx = {-1, ""};

    for (int _ = 0; _ < 50; _++)
    {
        int l = ((rand()<<15) + rand())%n+1;

        vector<int> good;
        for (int i=0; i<k; i++)
            if (a[l][i])
                good.pb(i);
        int m = good.size();
        unordered_map<int, int> mp;
        for (int i=1; i<=n; i++)
        {
        int mask = 0;
        for (int j=0; j<m; j++)
            if (a[i][good[j]])
                mask |= (1<<j);
        masks[i] = mask;
        }

        vector<int> sos(1<<m, 0);
        for (int i=1; i<=n; i++)
            sos[masks[i]]++;
        for (int i=0; i<m; i++)
        for (int j=0; j<(1<<m); j++)
            if (((j>>i)&1) == 0)
            {
                sos[j] += sos[j | (1<<i)];
            }

        for (int j=0; j<(1<<m); j++)
        if (sos[j] >= (n+1)/2)
        {
            string s = "";
            int jx=0;
            for (int i=0; i<k; i++)
            {
                if (!a[l][i])
                    s+="0";
                else
                    s+=char( '0' + ((j >> (jx++)) & 1) );
            }
            mx = max(mx, { __builtin_popcount(j), s});
        }
    }

    cout<<mx.se<<"\n";
}