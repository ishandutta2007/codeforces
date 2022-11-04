#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tree;

void update(int now, int l, int r, int pos, int val)
{
    tree[now] += val;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos)
    {
        update(now * 2, l, mid, pos, val);
    }
    else
    {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
}

int get_sum(int now, int l, int r, int l1, int r1)
{
    if(l > r)
    {
        return 0;
    }
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
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> vals;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            vals.insert(a[i]);
        }
        map<int, int> d;
        int now = 0;
        for(const auto& el : vals)
        {
            d[el] = now++;
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = d[a[i]];
        }
        tree.assign(4 * now + 5, 0);
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            int here = get_sum(1, 0, now - 1, 0, a[i] - 1);
            here = min(here, get_sum(1, 0, now - 1, a[i] + 1, now - 1));
            res += here;
            update(1, 0, now - 1, a[i], 1);
        }
        cout << res << '\n';
    }
}