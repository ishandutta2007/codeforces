#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{

    int start[100500];
    char vhod[100500];
    int nom[100500];

    int active = 0;

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> vhod[i] >> nom[i];

    for (int i = 1; i <= n; i++)
        start[i] = -1;

    for (int i = 0; i < m; i++)
    {
        if (vhod[i] == '+')
        {
            if (start[nom[i]] == -1) start[nom[i]] = 0;
        }
        else
        {
            if (start[nom[i]] == -1) {start[nom[i]] = 1; active++;}
        }
    }

    vector <int> ans;
    set <int> poss;
    for (int i = 1; i <= n; i++)
        if (start[i] == -1) ans.push_back(i);

    int cand[100500];
    for (int i = 1; i <= n; i++)
        if (start[i] != -1) cand[i] = 1;
        else cand[i] = 0;

    if (active != 0)
    {
        for (int i = 1; i <= n; i++)
            if (start[i] == 0) cand[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        if (cand[i] == 1) poss.insert(i);

    for (int i = 0; i < m; i++)
    {
        if (vhod[i] == '+')
        {
            if (active == 0)
            {
                int was = 0;
                for (set <int> :: iterator it = poss.begin(); it != poss.end(); it++)
                    if (*it != nom[i]) cand[*it] = 0;
                    else was++;
                poss.clear();
                if (was == 1) poss.insert(nom[i]);
            }
            active++;
        }
        else
        {
            if (active != 1 && poss.count(nom[i]) != 0) poss.erase(nom[i]);
            active--;
        }
    }

    for (set <int> :: iterator it = poss.begin(); it != poss.end(); it++)
        ans.push_back(*it);
    sort  (ans.begin(), ans.end());

    cout << ans.size();
    if (ans.size() > 0) cout << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

}