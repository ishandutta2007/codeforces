#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n, x;
string s;

void solve()
{
    cin >> n >> x >> s;
    ll bal = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == '0') bal++; else bal--;
    if (bal == 0)
    {
        bal = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (bal == x)
            {
                cout << -1 << "\n";
                return;
            }
            if (s[i] == '0') bal++;
            else bal--;
        }
        cout << 0 << "\n";
        return;
    }
    ll curb = 0;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int kek = x - curb;
        if (1LL * bal * kek >= 0 && kek % bal == 0) ans++;
        if (s[i] == '0') curb++;
        else curb--;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}