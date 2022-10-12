#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 5e6;

vector<int> items[N];
vector<pair<int, int> > dif[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        items[a[i]].push_back(i + 1);
    }

    vector<int> huge;
    for (int i = 0; i < N; i++)
    {
        if (items[i].size() >= 4)
        {
            cout << "YES\n";
            cout << items[i][0] << " " << items[i][1] << " " << items[i][2] << " " << items[i][3] << "\n";
            return 0;
        }
        if (items[i].size() == 3)
        {
            items[i].pop_back();
        }
        if (items[i].size() == 2)
            huge.push_back(i);
    }
    if (huge.size() >= 2)
    {
        cout << "YES\n";
        cout << items[huge[0]][0] << " " << items[huge[1]][0] << " " << items[huge[0]][1] << " " << items[huge[1]][1] << "\n";
        return 0;
    }
    int x = -1;
    if (huge.size())
        x = huge[0];

    for (int i = 0; i < x; i++)
    {
        if (items[i].size() && items[2 * x - i].size())
        {
            cout << "YES\n";
            cout << items[i][0] << " " << items[2 * x - i][0] << " " << items[x][0] << " " << items[x][1] << "\n";
            return 0;
        }
    }
    vector<pair<int, int> > b;
    for (int i = 0; i < N; i++)
    {
        if (items[i].size()) b.push_back({i, items[i][0]});
    }
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int x = b[i].first - b[j].first;
            dif[x].push_back({j, i});
            if (dif[x].size() >= 2)
            {
                if (dif[x][0].second == dif[x][1].first) continue;
                cout << "YES\n";
                cout << b[dif[x][0].first].second << " " << b[dif[x][1].second].second << " " << b[dif[x][1].first].second << " " << b[dif[x][0].second].second << "\n";
                return 0;
            }
            if (dif[x].size() >= 3)
            {
                cout << "YES\n";
                cout << b[dif[x][0].first].second << " " << b[dif[x][2].second].second << " " << b[dif[x][2].first].second << " " << b[dif[x][0].second].second << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}