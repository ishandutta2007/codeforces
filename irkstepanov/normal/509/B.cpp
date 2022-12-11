#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    vector <pii> v;
    int n, k;

    cin >> n >> k;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(all(v));

    if (k + v[0].first < v[n - 1].first) {cout << "NO\n"; return 0;}
    cout << "YES\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (v[j].second == i)
    {
        int z = v[j].first, k;
        for (k = 1; k <= v[0].first + 1 && k <= z; k++)
            cout << "1 ";
        while (k <= z)
        {
            cout << k - v[0].first << " ";
            ++k;
        }
        cout << "\n";
    }

}