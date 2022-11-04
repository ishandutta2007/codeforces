#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_otr(int l, int r, vector<int>& pref1, vector<int>& pref2)
{
    if(l > r)
    {
        return 0;
    }
    return (pref1[r + 1] - pref1[l]) - (pref2[r + 1] - pref2[l]);
}

int find_pos(int l, int r, vector<int>& pref1, vector<int>& pref2, unordered_map<int, set<int> >& d1, unordered_map<int, set<int> >& d2)
{
    int val = get_otr(l, r, pref1, pref2);
    /////////////////////////
    int need = (val - 1) / 2;
    need += get_otr(r + 1, pref1.size() - 2, pref1, pref2);
    //cout << need << endl;
    auto it = d1[need].lower_bound(l);
    if(it != d1[need].end() && *it <= r)
    {
        return *it;
    }
    ///////////////////
    need = (val + 1) / 2;
    need += get_otr(r + 1, pref1.size() - 2, pref1, pref2);
    it = d2[need].lower_bound(l);
    if(it != d2[need].end() && *it <= r)
    {
        return *it;
    }
    cout << "##################\n";
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pref1(n + 1), pref2(n + 1);
        for(int i = 1; i <= n; i++)
        {
            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];
            int here = 1;
            if(s[i - 1] == '-')
            {
                here = -1;
            }
            if(i % 2 == 1)
            {
                pref1[i] += here;
            }
            else
            {
                pref2[i] += here;
            }
        }
        unordered_map<int, set<int> > d1;
        unordered_map<int, set<int> > d2;
        for(int i = 0; i < n; i++)
        {
            int val = get_otr(i + 1, n - 1, pref1, pref2);
            int here = 1;
            if(s[i] == '-')
            {
                here = 0;
            }
            if((here + i) % 2 == 1)
            {
                d1[val].insert(i);
                //cout << "1 " << val << ' ' << i << endl;
            }
            else
            {
                d2[val].insert(i);
                //cout << "2 " << val << ' ' << i << endl;
            }
        }
        for(int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            if((r - l + 1) % 2 == 1)
            {
                cout << "1\n";
                cout << find_pos(l, r, pref1, pref2, d1, d2) + 1 << '\n';
                continue;
            }
            if(pref1[r + 1] - pref1[l] == pref2[r + 1] - pref2[l])
            {
                cout << "0\n";
            }
            else
            {
                cout << "2\n";
                cout << find_pos(l + 1, r, pref1, pref2, d1, d2) + 1 << ' ' << l + 1 << '\n';
            }
        }
    }
}