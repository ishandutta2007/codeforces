#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define mp make_pair
#include <set>
using namespace std;

vector<int> ans (1000);
vector<pair<pair<int, int>, int> > a;
int n;
set<int> c;
int lef;

void try_it (int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x <= a[i].first.first && x >= a[i].first.second)
        {
            ans[a[i].second] = x;
            a[i] = mp(mp(-1, -1), -1);
            lef--;
            return;
        }
    }
}

int main()
{
    cin >> n;
    lef = n;
    int t, b, x;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> b;
        a.pb(mp(mp(b, t), i));
        c.insert(b);
        c.insert(t);
    }
    sort(a.begin(), a.end());
    set<int> :: iterator it = c.begin();
    for (int i = 0;lef;)
    {
        i = *it;
        for (int j = 0; j < 100; j++)
        {
            try_it(i + j);
        }
        i += 100;
        while (*it <= i && it != c.end())
            it++;
    }
    for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
    return 0;
}