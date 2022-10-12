#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<int> &l, vector<int> &r, vector<int> &order)
{
    if (v == -1) return;
    dfs(l[v], l, r, order);
    order.push_back(v);
    dfs(r[v], l, r, order);
}

void dfs(int v, vector<int> &l, vector<int> &r, vector<int> &wd,
         vector<int> &t, int &k, int ld, int cur)
{
    if (v == -1) return;
    dfs(l[v], l, r, wd, t, k, ld, cur + 1);
    if (l[v] != -1 && t[l[v]]) t[v] = 1;
    if (!t[v] && wd[v] && k >= cur - ld)
    {
        t[v] = 1;
        k -= cur - ld;
    }
    if (t[v]) ld = cur;
    if (t[v] || wd[v]) dfs(r[v], l, r, wd, t, k, ld, cur + 1);
    if (r[v] != -1 && t[r[v]]) t[v] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    vector<int> l(n), r(n);
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i], l[i]--, r[i]--;

    vector<int> order;
    dfs(0, l, r, order);

    vector<int> want_doubling(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + 1 == n)
        {
            want_doubling[order[i]] = 0;
        }
        else
        {
            if (s[order[i + 1]] > s[order[i]])
                want_doubling[order[i]] = 1;
            if (s[order[i + 1]] == s[order[i]])
                want_doubling[order[i]] = want_doubling[order[i + 1]];
        }
    }

    vector<int> t(n);
    dfs(0, l, r, want_doubling, t, k, -1, 0);

    //cout << accumulate(t.begin(), t.end(), 0) << "\n";
    //cout << k << "\n";

    for (int i = 0; i < n; i++)
    {
        if (t[order[i]]) cout << s[order[i]] << s[order[i]];
        else cout << s[order[i]];
    }
}