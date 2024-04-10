#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int> > p;
    for (int i = 0; i < n; i++)
        cin >> a[i], p.push_back({a[i], i});

    sort(p.begin(), p.end());
    map<int, int> cnt;

    vector<int> L(n), R(n), act(n);
    iota(L.begin(), L.end(), 0);
    iota(R.begin(), R.end(), 0);

    int ans = p[0].first + 1, loc = 0;
    for (int i = 0; i < p.size(); i++)
    {
        int pos = p[i].second;
        act[pos] = 1;
        int LL = pos;
        if (pos - 1 >= 0 && act[pos - 1]) LL = L[pos - 1];
        int RR = pos;
        if (pos + 1 < n && act[pos + 1]) RR = R[pos + 1];

        if (LL < pos)
        {
            cnt[pos - LL]--;
            if (cnt[pos - LL] == 0)
                cnt.erase(pos - LL);
        }
        if (pos < RR)
        {
            cnt[RR - pos]--;
            if (cnt[RR - pos] == 0)
                cnt.erase(RR - pos);
        }
        cnt[RR - LL + 1]++;
        if (cnt.size() == 1)
        {
            auto it = *cnt.begin();
            //cout << it.first << " " << it.second << endl;
            if (it.second > loc)
            {
                loc = it.second;
                ans = p[i].first + 1;
            }
        }

        R[LL] = RR;
        L[RR] = LL;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}