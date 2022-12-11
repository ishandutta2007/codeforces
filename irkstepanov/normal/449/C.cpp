#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

int main()
{

    int n;
    vector <char> prime(100500, true);
    cin >> n;

    vector <int> p;
    for (int i = 2; i <= n / 2; i++)
        if (prime[i])
    {
        p.pb(i);
        for (int j = 2 * i; j <= n / 2; j += i)
            prime[j] = false;
    }

    vector <char> used(100500, false);
    vector <pii> ans;

    for (int i = 1; i < p.size(); i++)
    {
        vector <int> tmp;
        for (int j = 1; p[i] * j <= n; j++)
            if (!used[p[i] * j]) tmp.pb(p[i] * j);
        if (tmp.size() % 2)
        {
            if (tmp.size() == 1) continue;
            tmp[1] = tmp[0];
            for (int j = 1; j < tmp.size(); j += 2)
            {
                ans.pb(mp(tmp[j], tmp[j + 1]));
                used[tmp[j]] = true;
                used[tmp[j + 1]] = true;
            }
        }
        else
        {
            for (int j = 0; j < tmp.size(); j += 2)
            {
                ans.pb(mp(tmp[j], tmp[j + 1]));
                used[tmp[j]] = true;
                used[tmp[j + 1]] = true;
            }
        }
    }

    vector <int> add;
    for (int i = 2; i <= n; i += 2)
        if (!used[i]) add.pb(i);

    if (add.size() % 2) add.pop_back();

    cout << ans.size() + add.size() / 2 << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].fi << " " << ans[i].se << "\n";

    for (int i = 0; i < add.size(); i += 2)
        cout << add[i] << " " << add[i + 1] << "\n";

}