#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tree(4000001, 0);
vector<int> to_clean;

void clear_tree()
{
    for(int i = 0; i < to_clean.size(); i++)
    {
        tree[to_clean[i]] = 0;;
    }
    to_clean.clear();
}

void add(int now, int l, int r, int pos, int val)
{
    to_clean.push_back(now);
    if(l == r)
    {
        tree[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos)
    {
        add(now * 2, l, mid, pos, val);
    }
    else
    {
        add(now * 2 + 1, mid + 1, r, pos, val);
    }
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

int get_sum(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return 0;
    }
    if(l1 <= l && r <= r1)
    {
        return tree[now];
    }
    int mid = (l + r) / 2;
    return get_sum(now * 2, l, mid, l1, r1) + get_sum(now * 2 + 1, mid + 1, r, l1, r1);
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    pair<int, int> ar = {a.second, a.first};
    pair<int, int> br = {b.second, b.first};
    return ar < br;
}

ostream& operator<<(ostream& out, pair<int, int>& a)
{
    out << a.first << ' ' << a.second;
    return out;
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
        int n, m, k;
        cin >> n >> m >> k;
        set<int> x, y;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            x.insert(a);
        }
        for(int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            y.insert(a);
        }
        vector<pair<int, int>> p(k);
        for(int i = 0; i < k; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        sort(p.begin(), p.end());
        clear_tree();
        ll res = 0;
        int prev = 0;
        for(int i = 0; i < k; i++)
        {
            if(x.find(p[i].first) != x.end() && y.find(p[i].second) == y.end())
            {
                if(p[prev].first != p[i].first)
                {
                    for(; prev < i; prev++)
                    {
                        if(x.find(p[i].first) != x.end() && y.find(p[i].second) == y.end())
                        {
                            add(1, 0, 1000000, p[prev].second, 1);
                        }   
                    }
                }
                auto it = y.lower_bound(p[i].second);
                int right = (*it) - 1;
                --it;
                int left = (*it) + 1;
                int ans = get_sum(1, 0, 1000000, left, right);
                res += ans;
                //cout << p[i] << ' ' << ans << '\n';
            }
        }
        clear_tree();
        sort(p.begin(), p.end(), cmp);
        prev = 0;
        for(int i = 0; i < k; i++)
        {
            if(y.find(p[i].second) != y.end() && x.find(p[i].first) == x.end())
            {
                if(p[prev].second != p[i].second)
                {
                    for(; prev < i; prev++)
                    {
                        if(y.find(p[i].second) != y.end() && x.find(p[i].first) == x.end())
                        {
                            add(1, 0, 1000000, p[prev].first, 1);
                        }   
                    }
                }
                auto it = x.lower_bound(p[i].first);
                int right = (*it) - 1;
                --it;
                int left = (*it) + 1;
                int ans = get_sum(1, 0, 1000000, left, right);
                res += ans;
                //cout << p[i] << ' ' << ans << '\n';
            }
        }
        cout << res << '\n';
    }
}