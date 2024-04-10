#include <bits/stdc++.h>
 
typedef long long ll;
const int INF = 1e9;
 
using namespace std;
 
#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solver(int turn, ll &ans, ll a, ll b, ll c, vector<int> blocks, ll other0, ll single0, ll P, ll turns1)
{
    ll cur = 0;
    while (1)
    {
        if (turn == 1)
        {
            if (turns1 > 0)
            {
                turns1--;
                cur += b;
                ans = max(ans, cur);
            }
            else
            {
                return;
            }
        }
        else
        {
            if (turns1 == 0)
            {
                if (other0 > 0 || blocks.size() > 0)
                {
                    ans = max(ans, cur + a); /// it is the final move
                }
                if (single0 > 0) /// we are forced to remove single zero
                {
                    single0--;
                    cur -= c;
                    ans = max(ans, cur);
                    turns1++;
                }
            }
            else
            {
                if (blocks.size() > 0)
                {
                    blocks[blocks.size() - 1]--;
                    if (blocks.back() == 1)
                        blocks.pop_back(), single0++;
                    cur += a;
                    ans = max(ans, cur);
                }
                else if (other0 > 0)
                {
                    other0--;
                    cur += a;
                    ans = max(ans, cur);
                }
                else if (single0 > 0)
                {
                    single0--;
                    turns1++;
                    cur -= c;
                    ans = max(ans, cur);
                }
                else if (P > 0)
                {
                    P--;
                    cur -= c;
                    ans = max(ans, cur);
                }
                else
                {
                    return;
                }
            }
        }
        turn ^= 1;
    }
}
 
ll solve(int n, string s, ll a, ll b, ll c)
{
    if (n == 1)
    {
        return 0ll;
    }
 
    // +a for "00" -> "0"
    // +b for "11" -> "1"
    // -c for "0"->""
 
    ll ans = 0;
 
    ll fir1 = INF, lst1 = -1;
    forn(i, n) if (s[i] == '1')
    {
        lst1 = i;
    }
    forn(i, n) if (s[i] == '1')
    {
        fir1 = i;
        break;
    }
    if (fir1 == INF)
    {
        return a;
    }
    vector<int> blocks;
    ll P = 0;
    if (s[0] == '0') P++;
    if (s.back() == '0') P++;
    ll other0 = max(fir1 - 1, 0ll) + max(n - lst1 - 2, 0ll);
    ll turns1 = 0;
    for (int i = 0; i + 1 < n; i++) if (s[i] == s[i + 1] && s[i] == '1')
        turns1++;
    ll single0 = 0;
    for (int i = fir1; i < lst1; )
    {
        int j = i + 1;
        while (s[j] != '1')
            j++;
        int len = j - i - 1;
        if (len == 1) single0++;
        else if (len > 1) blocks.push_back(len);
        i = j;
    }
    sort(rall(blocks));
 
    solver(0, ans, a, b, c, blocks, other0, single0, P, turns1);
    solver(1, ans, a, b, c, blocks, other0, single0, P, turns1);
 
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        ll ans3 = solve(n, s, a, b, c);
        cout << ans3 << "\n";
    }
}