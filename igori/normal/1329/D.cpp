#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define re return

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

const int N = 500000;
const int alpha = 26;

void solve()
{
    string s;
    cin >> s;
    vector<int> c(alpha);
    for (int i = 0; i + 1 < s.size(); i++) if (s[i] == s[i + 1]) c[s[i] - 'a']++;
    int si = 0, mx = 0;
    for (int i = 0; i < alpha; i++) si += c[i], mx = max(mx, c[i]);
    int ans = max((si + 1) / 2, mx) + 1;
    vector<pair<int, int> > answ;
    vector<pair<int, int> > st, str;
    str.push_back({s[0] - 'a', 1});
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            int t = 0;
            if (st.size() && s[i] - 'a' != st.back().first)
            {
                int x = s[i] - 'a', y = st.back().first;
                int si = 0, mx = 0;
                for (int i = 0; i < alpha; i++) si += c[i], mx = max(mx, c[i]);
                int si2 = 0, mx2 = 0;
                for (int i = 0; i < alpha; i++) si2 += c[i] - (i == x || i == y), mx2 = max(mx2, c[i] - (i == x || i == y));
                int cur = max((si + 1) / 2, mx);
                int ncur = max((si2 + 1) / 2, mx2);
                if (ncur < cur)
                {
                    int pos = str.back().second;
                    while (1)
                    {
                        pair<int, int> k = str.back();
                        str.pop_back();
                        if (k.first == str.back().first)
                        {
                            answ.push_back({k.second, pos});
                            break;
                        }
                    }
                    c[x]--;
                    st.pop_back();
                    c[y]--;
                    t = 1;
                }
            }
            if (t == 0)
            {
                st.push_back({s[i] - 'a', i + 1});
            }
        }
        str.push_back({s[i] - 'a', str.size() + 1});
    }
    s = "";
    for (int i = 0; i < str.size(); i++)
    {
        s += (char)(str[i].first + 'a');
    }
    mx = 0, si = 0;
    for (int i = 0; i < alpha; i++) mx = max(mx, c[i]), si += c[i];
    while (s.size())
    {
        int x = s.size();
        while ((int)s.size() - 2 >= 0 && s[s.size() - 1] != s[s.size() - 2])
        {
            s.pop_back();
        }
        s.pop_back();
        answ.push_back({s.size() + 1, x});
    }
    cout << answ.size() << "\n";
    forn(i, answ.size()) cout << answ[i].first << " " << answ[i].second << "\n";
}

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}