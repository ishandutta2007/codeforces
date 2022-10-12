#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

const ll inf = 1e9 + 1;
const int N = 100000;

int cnt[N];

void solve()
{
    int n;
    cin >> n;
    int K = 0;

    vector<int> huge;
    vector<int> small;
    vector<vector<int> > a(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
            cin >> a[i][j];
        sort(all(a[i]));
        tot += k;
    }
    {
        vector<int> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                st.push_back(a[i][j]);
            }
        }
        sort(all(st));
        map<int, int> mm;
        for (int i = 0; i < st.size(); i++)
            mm[st[i]] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                a[i][j] = mm[a[i][j]];
            }
        }
    }
    while ((K + 1) * (K + 1) * 20 <= tot) K++;
    for (int i = 0; i < n; i++)
    {
        if (a[i].size() > K) huge.push_back(i);
        else small.push_back(i);
    }
    vector<vector<pii> > connect(tot);
    for (auto id : small)
    {
        for (int i = 0; i < a[id].size(); i++)
        {
            for (int j = i + 1; j < a[id].size(); j++)
            {
                connect[a[id][i]].push_back({a[id][j], id});
            }
        }
    }
    vector<pair<int, int> > lm(tot, {-1, -1});
    for (int i = 0; i < tot; i++)
    {
        for (auto e : connect[i])
        {
            int x = e.first;
            int id2 = e.second;
            if (lm[x].first == i)
            {
                cout << lm[x].second + 1 << " " << id2 + 1 << "\n";
                return;
            }
            lm[x] = {i, id2};
        }
    }
    vector<pair<int, int> > ints;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            ints.push_back({a[i][j], i});
        }
    }
    sort(all(ints));
    for (auto id : huge)
    {
        int j = 0;
        for (int i = 0; i < ints.size(); i++)
        {
            while (j + 1 < a[id].size() && a[id][j + 1] <= ints[i].first)
                j++;
            if (a[id][j] == ints[i].first)
                cnt[ints[i].second]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] >= 2 && id != i)
            {
                for (int j = i; j < n; j++)
                    cnt[j] = 0;
                cout << id + 1 << " " << i + 1 << "\n";
                return;
            }
            cnt[i] = 0;
        }
    }
    cout << -1 << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}