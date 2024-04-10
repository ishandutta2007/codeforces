#include <bits/stdc++.h>
 
using namespace std;
 
int answer(set<vector<int> > &byL, set<vector<int> > &byR, map<pair<int, int>, set<int> > &all)
{
    if (byL.size() == 0)
        return 0;
    int L = (*byL.begin())[0];
    int R = (*byR.rbegin())[0];
    int Lc = (*byL.begin())[1];
    int Rc = -(*byR.rbegin())[1];
    if (all[{L, R}].size() != 0)
    {
        int x = *all[{L, R}].begin();
        if (x < Lc + Rc)
            return x;
    }
    return Lc + Rc;
}
 
void solve()
{
    int q;
    cin >> q;
    set<vector<int> > byL, byR;
    map<pair<int, int>, set<int> > all;
    while (q--)
    {
        char t = '+';
        int l, r, c;
        cin >> l >> r >> c;
        if (t == '+')
        {
            byL.insert({l, c, r});
            byR.insert({r, -c, l});
            all[{l, r}].insert(c);
        }
        else
        {
            byL.erase({l, c, r});
            byR.erase({r, -c, l});
            all[{l, r}].erase(c);
        }
        cout << answer(byL, byR, all) << "\n";
    }
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