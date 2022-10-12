#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
void add(int pos, int x, vector<int> &fenw)
{
    while (pos < fenw.size())
    {
        fenw[pos] += x;
        fenw[pos] %= MOD;
        pos |= (pos + 1);
    }
}
 
int get(int pos, vector<int> &fenw)
{
    int res = 0;
    while (pos >= 0)
    {
        res = res + fenw[pos];
        res %= MOD;
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
 
int weight_of_all_subseq(vector<int> seq)
{
    vector<int> dp_up(seq.size());
    vector<int> fenw1(seq.size());
    for (int i = (int)seq.size() - 1; i >= 0; i--)
    {
        dp_up[i] = (1ll + get(seq.size() - 1, fenw1) - get(seq[i], fenw1) + MOD) % MOD;
        add(seq[i], dp_up[i], fenw1);
    }
    vector<int> fenw2(seq.size());
    vector<int> dp_down(seq.size());
    for (int i = 0; i < seq.size(); i++)
    {
        dp_down[i] = (1ll + get(seq[i], fenw2)) % MOD;
        add(seq[i], dp_down[i], fenw2);
    }
    vector<int> suf_mx;
    vector<int> is_suf_mx(seq.size());
    int mx = 0;
    for (int i = (int)seq.size() - 1; i >= 0; i--)
    {
        mx = max(mx, seq[i]);
        if (seq[i] == mx)
            suf_mx.push_back(i), is_suf_mx[i] = 1;
    }
 
    vector<int> q(seq.size());
    for (int i = 0; i < seq.size(); i++)
        q[seq[i]] = i;
 
    vector<int> dp_up_fix(seq.size());
    vector<int> fenw3(seq.size());
    int lst = seq.size() - 1;
    for (int x = (int)seq.size() - 1; x >= 0; x--)
    {
        if (is_suf_mx[q[x]])
        {
            dp_up_fix[x] = 1;
            for (int j = x + 1; j <= lst; j++)
                add(q[j], (MOD - dp_up_fix[j]) % MOD, fenw3);
            add(q[x], dp_up_fix[x], fenw3);
            lst = x;
            continue;
        }
        dp_up_fix[x] = (get(q[lst], fenw3) - get(q[x], fenw3) + MOD) % MOD;
        add(q[x], dp_up_fix[x], fenw3);
    }
 
    int ans = 0;
    for (int i = (int)seq.size() - 1; i >= 0; i--)
    {
        ans = (ans + 1ll * dp_down[i] * (dp_up[i] + MOD - dp_up_fix[seq[i]])) % MOD;
    }
    return ans;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i].first, b[i].second = -i;
    vector<int> a(n);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        a[-b[i].second] = i;
    cout << weight_of_all_subseq(a) << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}