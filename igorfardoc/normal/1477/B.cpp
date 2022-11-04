#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int amount0 = 0;
    int len = 0;
    bool filled0 = false;
    bool filled1 = false;
};
vector<Node> tree;
string s, t;

void build_tree(int now, int l, int r)
{
    tree[now].amount0 = 0;
    tree[now].filled0 = false;
    tree[now].filled1 = false;
    tree[now].len = r - l + 1;
    if(l == r)
    {
        tree[now].amount0 = (t[l] == '0');
        return;
    }
    int mid = (l + r) / 2;
    build_tree(now * 2, l, mid);
    build_tree(now * 2 + 1, mid + 1, r);
    tree[now].amount0 = tree[now * 2].amount0 + tree[now * 2 + 1].amount0;
}



void push(int now)
{
    if(tree[now].filled1)
    {
        tree[now * 2].filled1 = true;
        tree[now * 2 + 1].filled1 = true;
        tree[now * 2].filled0 = false;
        tree[now * 2 + 1].filled0 = false;
        tree[now].amount0 = 0;
    }
    if(tree[now].filled0)
    {
        tree[now * 2].filled0 = true;
        tree[now * 2 + 1].filled0 = true;
        tree[now * 2].filled1 = false;
        tree[now * 2 + 1].filled1 = false;
        tree[now].amount0 = tree[now].len;
    }
    tree[now].filled1 = false;
    tree[now].filled0 = false;
}

void update(int now)
{
    int am = 0;
    if(tree[now * 2].filled0)
    {
        am += tree[now * 2].len;
    }
    else if(tree[now * 2].filled1)
    {

    }
    else
    {
        am += tree[now * 2].amount0;
    }
    if(tree[now * 2 + 1].filled0)
    {
        am += tree[now * 2 + 1].len;
    }
    else if(tree[now * 2 + 1].filled1)
    {

    }
    else
    {
        am += tree[now * 2 + 1].amount0;
    }
    tree[now].amount0 = am;
}

int get_amount0(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return 0;
    }
    push(now);
    if(l >= l1 && r <= r1)
    {
        return tree[now].amount0;
    }
    int mid = (l + r) / 2;
    return get_amount0(now * 2, l, mid, l1, r1) + get_amount0(now * 2 + 1, mid + 1, r, l1, r1);
}

void fill0(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return;
    }
    push(now);
    if(l >= l1 && r <= r1)
    {
        tree[now].filled0 = true;
        tree[now].amount0 = tree[now].len;
        return;
    }
    int mid = (l + r) / 2;
    fill0(now * 2, l, mid, l1, r1);
    fill0(now * 2 + 1, mid + 1, r, l1, r1);
    update(now);

}
void fill1(int now, int l, int r, int l1, int r1)
{
    if(l > r1 || l1 > r)
    {
        return;
    }
    push(now);
    if(l >= l1 && r <= r1)
    {
        tree[now].filled1 = true;
        tree[now].amount0 = 0;
        return;
    }
    int mid = (l + r) / 2;
    fill1(now * 2, l, mid, l1, r1);
    fill1(now * 2 + 1, mid + 1, r, l1, r1);
    update(now);
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
    int t1;
    cin >> t1;
    tree.resize(2000000);
    while(t1--)
    {
        int n, q;
        cin >> n >> q;
        cin >> s >> t;
        vector<pair<int, int> > q1(q);
        for(int i = 0; i < q; i++)
        {
            cin >> q1[i].first >> q1[i].second;
            --q1[i].first;
            --q1[i].second;
        }
        build_tree(1, 0, n - 1);
        bool ok = true;
        for(int i = q - 1; i >= 0; i--)
        {
            int l = q1[i].first;
            int r = q1[i].second;
            int len = r - l + 1;
            int amount0 = get_amount0(1, 0, n - 1, l, r);
            if(len % 2 == 0 && amount0 == len / 2)
            {
                ok = false;
                break;
            }
            if(len / 2 >= amount0)
            {
                fill1(1, 0, n - 1, l, r);
            }
            else
            {
                fill0(1, 0, n - 1, l, r);
            }
        }
        //cout << ok << endl;
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            int am = get_amount0(1, 0, n - 1, i, i);
            if((s[i] == '0' && am == 1) || (s[i] == '1' && am == 0))
            {

            }
            else
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}