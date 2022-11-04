#include<bits/stdc++.h>
#define INF 100000000000000000ll
using namespace std;
typedef long long ll;
ll tree1[500000];
ll tree2[500000];

void build_max(int now, int l, int r, vector<ll>& a)
{
    if(l == r)
    {
        tree1[now] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_max(now * 2, l, mid, a);
    build_max(now * 2 + 1, mid + 1, r, a);
    tree1[now] = max(tree1[now * 2], tree1[now * 2 + 1]);
}
ll get_max(int now, int l, int r, int l1, int r1)
{
    if(l1 > r || l > r1)
    {
        return -INF;
    }
    if(l1 <= l && r <= r1)
    {
        return tree1[now];
    }
    int mid = (l + r) / 2;
    return max(get_max(now * 2, l, mid, l1, r1), get_max(now * 2 + 1, mid + 1, r, l1, r1));
}
void build_min(int now, int l, int r, vector<ll>& a)
{
    if(l == r)
    {
        tree2[now] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_min(now * 2, l, mid, a);
    build_min(now * 2 + 1, mid + 1, r, a);
    tree2[now] = min(tree2[now * 2], tree2[now * 2 + 1]);
}
ll get_min(int now, int l, int r, int l1, int r1)
{
    if(l1 > r || l > r1)
    {
        return INF;
    }
    if(l1 <= l && r <= r1)
    {
        return tree2[now];
    }
    int mid = (l + r) / 2;
    return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1));
}
int sign(int i)
{
    if(i > 0)
    {
        return 1;
    }
    if(i < 0)
    {
        return -1;
    }
    return 0;
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> sum1(n + 1), sum2(n + 1);
    vector<int> get_next(n);
    int prev = n;
    for(int i = n - 1; i >= 0; i--)
    {
        get_next[i] = prev;
        if(i == 0 || sign(a[i] - b[i]) != sign(a[i - 1] - b[i - 1]))
        {
            prev = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        sum1[i] = sum1[i - 1] + a[i - 1];
        sum2[i] = sum2[i - 1] + b[i - 1];
    }
    vector<ll> allfir(n + 1);
    for(int i = 1; i <= n; i++)
    {
        allfir[i] = allfir[i - 1] + max(0, b[i - 1] - a[i - 1]);
    }
    vector<ll> pref1(n + 1);
    for(int i = 1; i <= n; i++)
    {
        if(b[i - 1] < a[i - 1])
        {
            pref1[i] = pref1[i - 1] + b[i - 1] - a[i - 1];
        }
        else
        {
            pref1[i] = 0;
        }
        //pref1[i] = pref1[i - 1] - a[i - 1] + b[i - 1];
        //cout << pref1[i] << ' ';
    }
    vector<ll> fordo(n + 1);
    for(int i = 1; i <= n; i++)
    {
        fordo[i] = pref1[i] + allfir[i];
    }
    build_min(1, 0, n, fordo);
    vector<ll> pref2(n + 1);
    for(int i = 1; i <= n; i++)
    {
        pref2[i] = pref2[i - 1] + b[i - 1] - a[i - 1];
    }
    build_min(1, 0, n, pref2);
    build_max(1, 0, n, pref2);
    for(int _ = 0; _ < q; _++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if(sum2[r + 1] - sum2[l] != sum1[r + 1] - sum1[l])
        {
            cout << "-1\n";
            continue;
        }
        if(get_min(1, 0, n, l + 1, r + 1) - pref2[l] < 0)
        {
            cout << "-1\n";
            continue;
        }
        cout << get_max(1, 0, n, l + 1, r + 1) - pref2[l] << '\n';
    }
}