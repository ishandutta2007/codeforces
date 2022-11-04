#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;

struct Node
{
    pair<int, int> max = {0, 0};
    pair<int, int> val = {0, 0};
};
vector<Node> tree;
void update(int now, int l, int r)
{
    if(l == r)
    {
        tree[now].max = max(tree[now].max, tree[now].val);
        return;
    }
    tree[now].max = max(max(tree[now * 2].max, tree[now].val), max(tree[now * 2 + 1].max, tree[now].max));
}
void push(int now, int l, int r)
{
    if(l == r)
    {
        tree[now].max = max(tree[now].max, tree[now].val);
        return;
    }
    if(tree[now].val.first != -1)
    {
        tree[now * 2].val = max(tree[now * 2].val, tree[now].val);
        tree[now * 2 + 1].val = max(tree[now * 2 + 1].val, tree[now].val);
        tree[now].val.first = -1;
    }
}

void fill(int now, int l, int r, int l1, int r1, int val, int who)
{
    if(l > r1 || l1 > r)
    {
        return;
    }
    update(now, l, r);
    push(now, l, r);
    if(l1 <= l && r <= r1)
    {
        tree[now].val = max(tree[now].val, {val, who});
        update(now, l, r);
        return;
    }
    int mid = (l + r) / 2;
    fill(now * 2, l, mid, l1, r1, val, who);
    fill(now * 2 + 1, mid + 1, r, l1, r1, val, who);
    update(now, l, r);
}
pair<int, int> get_max(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return {-INF, -1};
    }
    update(now, l, r);
    push(now, l, r);
    if(l1 <= l && r <= r1)
    {
        return tree[now].max;
    }
    int mid = (l + r) / 2;
    return max(get_max(now * 2, l, mid, l1, r1), get_max(now * 2 + 1, mid + 1, r, l1, r1));
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> a(n);
    set<int> coords;
    /*fill(root, 1, 2, 1, 1);
    fill(root, 6, 8, 1, 1);
    auto p = get_max(root, 2, 5);
    cout << p.first << ' ' << p.second << endl;*/
    for(int i = 0; i < m; i++)
    {
        int j, l, r;
        cin >> j >> l >> r;
        --l;
        --r;
        --j;
        coords.insert(l);
        coords.insert(r);
        a[j].push_back({l, r});
    }
    int now = 0;
    unordered_map<int, int> d;
    for(auto& el : coords)
    {
        d[el] = now++;
    }
    tree.resize(4 * now + 3);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            a[i][j].first = d[a[i][j].first];
            a[i][j].second = d[a[i][j].second];
        }
    }
    int ans = 1;
    int from = 0;
    for(int j = 0; j < a[0].size(); j++)
    {
        fill(1, 0, now - 1, a[0][j].first, a[0][j].second, 1, 0);
    }
    vector<int> dp(n);
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int max1 = 0;
        int who = i;
        for(int j = 0; j < a[i].size(); j++)
        {
            auto p = get_max(1, 0, now - 1, a[i][j].first, a[i][j].second);
            if(p.first > max1)
            {
                max1 = p.first;
                who = p.second;
            }
        }
        //cout << i << ' ' << max1 << ' ' << who << endl;
        if(max1 + 1 > ans)
        {
            ans = max1 + 1;
            from = i;
        }
        dp[i] = who;
        for(int j = 0; j < a[i].size(); j++)
        {
            fill(1, 0, now - 1, a[i][j].first, a[i][j].second, max1 + 1, i);
        }
    }
    cout << n - ans << '\n';
    unordered_set<int> good;
    while(true)
    {
        good.insert(from);
        if(dp[from] == from)
        {
            break;
        }
        from = dp[from];
    }
    for(int i = 0; i < n; i++)
    {
        if(good.find(i) == good.end())
        {
            cout << i + 1 << ' ';
        }
    }
}