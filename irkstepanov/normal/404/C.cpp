#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    ll n, k;
    int d;
    vector <int> v[100500];

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d;
        v[d].pb(i);
    }

    if (v[0].size() != 1) {cout << "-1"; return 0;}
    vector <pair <int, int> > ans;

    for (int i = 1; i < n; i++)
    {
        if ((ll)v[i].size() > (ll)v[i - 1].size() * k) {cout << "-1"; return 0;}
        for (int j = 0; j < v[i].size(); j++)
            ans.pb(mp(v[i][j], v[i - 1][j / k]));
        if (i == 1) --k;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

}