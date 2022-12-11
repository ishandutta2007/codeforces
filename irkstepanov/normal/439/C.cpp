#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{

    int n, k, p;
    vector <int> chet, nech;

    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2) nech.pb(x);
        else chet.pb(x);
    }

    vector <vector <int> > ans;
    int posn = 0, posc = 0;
    int koln = 0, kolc = 0;

    for (int i = posn; i < nech.size() && ans.size() < k && i < k - p; i++)
    {
        vector <int> tmp;
        tmp.pb(nech[i]);
        ans.pb(tmp);
        ++posn;
        ++koln;
    }

    for (int i = posc; i < chet.size() && ans.size() < k; i++)
    {
        vector <int> tmp;
        tmp.pb(chet[i]);
        ans.pb(tmp);
        ++posc;
        ++kolc;
    }

    for (int i = posn; i < (int) nech.size() - 1 && ans.size() < k; i += 2)
    {
        vector <int> tmp;
        tmp.pb(nech[i]);
        tmp.pb(nech[i + 1]);
        ans.pb(tmp);
        posn += 2;
        ++kolc;
    }

    if (ans.size() < k || koln != k - p || kolc != p) {cout << "NO"; return 0;}

    for (int i = posc; i < chet.size(); i++)
    {
        ans[0].pb(chet[i]);
        ++posc;
    }

    for (int i = posn; i < (int) nech.size() - 1; i += 2)
    {
        ans[0].pb(nech[i]);
        ans[0].pb(nech[i + 1]);
        posn += 2;
    }

    if (posn != nech.size()) {cout << "NO"; return 0;}

    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

}