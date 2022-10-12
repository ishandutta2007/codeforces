#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    int id = 1;
    set<pair<int, int> > s1, s2;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            s1.insert({-x, id});
            s2.insert({id, -x});
            id++;
        }
        if (t == 2)
        {
            pair<int, int> it = *s2.begin();
            cout << it.first << " ";
            s1.erase({it.second, it.first});
            s2.erase(it);
        }
        if (t == 3)
        {
            pair<int, int> it = *s1.begin();
            cout << it.second << " ";
            s2.erase({it.second, it.first});
            s1.erase(it);
        }
    }
}