#include <iostream>
#include <vector>
#include <set>


#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> add[500000];
set<pii> scan;

int main()
{
    //freopen("stdin.in", "r", stdin);
    //freopen("stdout.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        add[l - 1].pb({i, w});
        add[r].pb({-i, w});
    }
    add[0].pb({m + 1, 0});
    for (int i = 0; i <= n; i++)
    {
        if (i > 0) {
            auto it = scan.begin();
            pii k = *it;
            while (i == k.second)
            {
                it++;
                k = *it;
            }
            cout << k.second << " ";
        }
        for (int j = 0; j < add[i].size(); j++)
        {
            if (add[i][j].first > 0)
            {
                scan.insert(add[i][j]);
            }
            else
            {
                add[i][j].first *= -1;
                scan.erase(add[i][j]);
            }
        }
    }
}