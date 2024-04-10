#include<bits/stdc++.h>
#define INF 1000000000
#define TREE 3000000
using namespace std;
typedef long long ll;
struct Node
{
    int val = 0;
    int min = 0;
};
Node tree[TREE];

void push(int now, int l, int r)
{
    if(l == r)
    {   
        tree[now].min += tree[now].val;
        tree[now].val = 0;
        return;
    }
    tree[now * 2].val += tree[now].val;
    tree[now * 2 + 1].val += tree[now].val;
    tree[now].val = 0;
}
void update(int now, int l, int r)
{
    if(l == r)
    {   
        tree[now].min += tree[now].val;
        tree[now].val = 0;
        return;
    }
    tree[now].min = min(tree[now * 2].min + tree[now * 2].val, tree[now * 2 + 1].min + tree[now * 2 + 1].val);
}

void update_val(int now, int l, int r, int l1, int r1, int val)
{
    if(l > r1 || l1 > r)
    {
        return;
    }
    push(now, l, r);
    update(now, l, r);
    if(l1 <= l && r <= r1)
    {
        tree[now].val += val;
        push(now, l, r);
        update(now, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_val(now * 2, l, mid, l1, r1, val);
    update_val(now * 2 + 1, mid + 1, r, l1, r1, val);
    update(now, l, r);
}
int get_min(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return INF;
    }
    push(now, l, r);
    update(now, l, r);
    if(l1 <= l && r <= r1)
    {
        return tree[now].min;
    }
    int mid = (l + r) / 2;
    return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1));
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
    scanf("%d", &n);
    scanf("%d", &m);
    vector<pair<int, pair<int, int>>> a(n);
    for(int i = 0; i < n; i++)
    {
        int l, r, w;
        scanf("%d %d %d", &l, &r, &w);
        --l;
        --r;
        --r;
        a[i].first = w;
        a[i].second.first = l;
        a[i].second.second = r;
    }
    /*update_val(1, 0, 2, 0, 1, 1);
    update_val(1, 0, 2, 1, 2, 1);
    cout << get_min(1, 0, 2, 0, 2) << endl;*/
    sort(a.begin(), a.end());
    int ans = INF;
    int l1 = 0;
    int r1 = -1;
    while(r1 != n - 1)
    {
        while(r1 != n - 1 && get_min(1, 0, m - 2, 0, m - 2) == 0)
        {
            update_val(1, 0, m - 2, a[r1 + 1].second.first, a[r1 + 1].second.second, 1);
            ++r1;
        }
        while(get_min(1, 0, m - 2, 0, m - 2) != 0)
        {
            ans = min(ans, a[r1].first - a[l1].first);
            update_val(1, 0, m - 2, a[l1].second.first, a[l1].second.second, -1);
            ++l1;
        }
    }
    printf("%d", ans);
}