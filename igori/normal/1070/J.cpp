#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> cnt(28);
    string s;
    cin >> s;
    for (int i = 0; i < k; i++)
        cnt[s[i] - 'A' + 1]++;

    ll ans = 1e9;
    if (max(n, m) >= 3000)
    {
        const int N = 30010;
        vector<bitset<N> > canP(28), canS(28);
        canP[0][0] = 1;
        canS[27][0] = 1;
        for (int i = 1; i <= 26; i++)
            canP[i] = canP[i - 1] | (canP[i - 1] << cnt[i]);

        for (int i = 26; i >= 1; i--)
            canS[i] = canS[i + 1] | (canS[i + 1] << cnt[i]);

        ans = 1ll * n * m;
        vector<bitset<N> > can(28);
        for (int c = 1; c <= 26; c++)
        {
            for (int i = 0; i < N; i++)
            {
                if (canP[c - 1][i]) can[c] |= canS[c + 1] << i;
            }
            ll x = n;
            while (x > 0)
            {
                while (!can[c][x]) x--;
                ll alpha = k - cnt[c] - x;
                ll betta = max(0ll, m - alpha);

                //cout << c << " " << x << endl;
                //for (int i = 0; i < 10; i++) cout << can[i] << " ";
                //cout << ": " << alpha << " " << betta << endl;

                if (n - x + betta <= cnt[c])
                    ans = min(ans, (n - x) * betta);
                x--;
            }
        }

        swap(n, m);

        for (int c = 1; c <= 26; c++)
        {
            ll x = n;
            while (x > 0)
            {
                while (!can[c][x]) x--;
                ll alpha = k - cnt[c] - x;
                ll betta = max(0ll, m - alpha);

                //cout << c << " " << x << endl;
                //for (int i = 0; i < 10; i++) cout << can[i] << " ";
                //cout << ": " << alpha << " " << betta << endl;

                if (n - x + betta <= cnt[c])
                    ans = min(ans, (n - x) * betta);
                x--;
            }
        }
    }
    else
    {
        const int N = 3001;
        vector<bitset<N> > canP(28), canS(28);
        canP[0][0] = 1;
        canS[27][0] = 1;
        for (int i = 1; i <= 26; i++)
            canP[i] = canP[i - 1] | (canP[i - 1] << cnt[i]);

        for (int i = 26; i >= 1; i--)
            canS[i] = canS[i + 1] | (canS[i + 1] << cnt[i]);

        ans = 1ll * n * m;
        vector<bitset<N> > can(28);
        for (int c = 1; c <= 26; c++)
        {
            for (int i = 0; i < N; i++)
            {
                if (canP[c - 1][i]) can[c] |= canS[c + 1] << i;
            }
            ll x = n;
            while (x > 0)
            {
                while (!can[c][x]) x--;
                ll alpha = k - cnt[c] - x;
                ll betta = max(0ll, m - alpha);

                //cout << c << " " << x << endl;
                //for (int i = 0; i < 10; i++) cout << can[i] << " ";
                //cout << ": " << alpha << " " << betta << endl;

                if (n - x + betta <= cnt[c])
                    ans = min(ans, (n - x) * betta);
                x--;
            }
        }

        swap(n, m);

        for (int c = 1; c <= 26; c++)
        {
            ll x = n;
            while (x > 0)
            {
                while (!can[c][x]) x--;
                ll alpha = k - cnt[c] - x;
                ll betta = max(0ll, m - alpha);

                //cout << c << " " << x << endl;
                //for (int i = 0; i < 10; i++) cout << can[i] << " ";
                //cout << ": " << alpha << " " << betta << endl;

                if (n - x + betta <= cnt[c])
                    ans = min(ans, (n - x) * betta);
                x--;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}