#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second

const int N = 200005;
const int INF = 1e9;

int n, m;
int x[N];
vector<int> pos[N];
int link[N];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i]--;
        pos[x[i]].push_back(i);
    }
    iota(link, link + m, 0);
    for (int i = 0; i + 1 < n; i++)
    {
        if (x[i] != x[i + 1])
            ans++;
    }
    cout << ans << "\n";
    for (int i = 0; i < m - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int ca = a;
        a = link[a], b = link[b];
        assert(pos[a].size());
        assert(pos[b].size());
        if (pos[a].size() < pos[b].size())
        {
            link[ca] = b;
            for (auto p : pos[a])
            {
                if (p - 1 >= 0 && x[p - 1] == b) ans--;
                if (p + 1 < n && x[p + 1] == b) ans--;
                pos[b].push_back(p);
            }
            for (auto p : pos[a])
            {
                x[p] = b;
            }
            pos[a].clear();
        }
        else
        {
            link[ca] = a;
            for (auto p : pos[b])
            {
                if (p - 1 >= 0 && x[p - 1] == a) ans--;
                if (p + 1 < n && x[p + 1] == a) ans--;
                pos[a].push_back(p);
            }
            for (auto p : pos[b])
            {
                x[p] = a;
            }
            pos[b].clear();
        }
        cout << ans << "\n";
    }
}