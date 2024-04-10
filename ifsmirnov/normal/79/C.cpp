#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 100500;
#define mp make_pair
#define pb push_back
#define se second
#define fi first
typedef long long ll;

int a[maxn];
int stop[maxn];
string s;
string t[15];
int n, k;

void scan();
void solve();

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scan();
    solve();
};
void scan()
{
    cin >> s >> k;
    n = s.length();
};
void solve()
{
    map<int, int> end;
    vector<pair<int, int> > cls;
    s += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    forn(i, k)
       cin >> t[i];
    forn(i, n) forn(j, k)
    {
        if (s.substr(i, t[j].length()) == t[j])
        {
            end[i+t[j].length()-1]++;
            cls.pb(mp(i, i+t[j].length()-1));
        }
    }

    int mx = 0, I = 0;
    for (int i = 0, pos = 0; i < n; i++)
    {
        int fin = end.empty() ? n : end.begin()->first;
        if (fin - i > mx)
            mx = fin-i, I=i;
        while (pos < cls.size() && cls[pos].fi == i)
        {
            end[cls[pos].second]--;
            if (end[cls[pos].second] == 0)
                end.erase(cls[pos].second);
            pos++;
        }
    }
    cout << mx << " " << I;
};