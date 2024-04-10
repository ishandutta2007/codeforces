#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

typedef long long ll;

const int N = 1000100;

int d[N + 1];

struct Node{
    int y;
    int cnt;
    int we;
    ll summ;
    int indexed;
    int minInd, maxInd;
    Node * L, * R;
};

void create(Node * Nd, int x, int index)
{
    Nd->y = (rand() << 15) + rand();
    Nd->cnt = 1;
    Nd->we = x;
    Nd->summ = x;
    Nd->indexed = index;
    Nd->minInd = index;
    Nd->maxInd = index;
}

int get_cnt(Node * Nd)
{
    if (!Nd) return 0;
    return Nd->cnt;
}

ll get_summ(Node * Nd)
{
    if (!Nd) return 0;
    return Nd->summ;
}

int get_minInd(Node * Nd)
{
    if (!Nd) return N;
    return Nd->minInd;
}

int get_maxInd(Node * Nd)
{
    if (!Nd) return -1;
    return Nd->maxInd;
}

void update(Node * Scope)
{
    Scope->cnt = get_cnt(Scope->L) + 1 + get_cnt(Scope->R);
    Scope->summ = get_summ(Scope->L) + Scope->we + get_summ(Scope->R);
    Scope->minInd = min(Scope->indexed, get_minInd(Scope->L));
    Scope->maxInd = max(Scope->indexed, get_maxInd(Scope->R));
}

Node * Merge(Node * L, Node * R)
{
    if (!L) return R;
    if (!R) return L;
    if (L->y < R->y)
    {
        L->R = Merge(L->R, R);
        update(L);
        return L;
    }
    else
    {
        R->L = Merge(L, R->L);
        update(R);
        return R;
    }
}

pair<Node *, Node *> Split_index(Node * Scope, int index)
{
    if (!Scope) return {nullptr, nullptr};
    if (Scope->indexed <= index)
    {
        pair<Node *, Node *> kek = Split_index(Scope->R, index);
        Scope->R = kek.first;
        update(Scope);
        return {Scope, kek.second};
    }
    else
    {
        pair<Node *, Node *> kek = Split_index(Scope->L, index);
        Scope->L = kek.second;
        update(Scope);
        return {kek.first, Scope};
    }
}

void Add_after_index(Node *& Root, int x, int index)
{
    Node * Nd = new Node();
    create(Nd, x, index);
    pair<Node *, Node *> kek = Split_index(Root, index);
    kek.first = Merge(kek.first, Nd);
    Root = Merge(kek.first, kek.second);
}

void Del_with_index(Node *& Root, int x, int index)
{
    pair<Node *, Node *> kek = Split_index(Root, index);
    kek.first = Split_index(kek.first, index - 1).first;
    Root = Merge(kek.first, kek.second);
}

ll Summ(Node * Scope, int l, int r)
{
    if (!Scope) return 0;
    int L = Scope->minInd, R = Scope->maxInd;
    if (l <= L && R <= r)
    {
        return Scope->summ;
    }
    if (R < l || r < L)
    {
        return 0;
    }
    long long center = 0;
    if (l <= Scope->indexed && Scope->indexed <= r)
        center = Scope->we;
    return Summ(Scope->L, l, r) + center + Summ(Scope->R, l, r);
}

void run(Node * Scope, Node *& Root2, Node *& Root3)
{
    if (!Scope) return;
    run(Scope->L, Root2, Root3);
    int x = d[Scope->we];
    if (Scope->we == 2)
    {
        Add_after_index(Root2, 2, Scope->indexed);
    }
    else
    {
        Add_after_index(Root3, x, Scope->indexed);
    }
    run(Scope->R, Root2, Root3);
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j * i <= N; j++)
        {
            d[i * j]++;
        }
    }
    Node * Root1 = nullptr;
    Node * Root2 = nullptr;
    Node * Root3 = nullptr;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            Add_after_index(Root1, a, i);
        }
        if (a == 2)
        {
            Add_after_index(Root2, a, i);
        }
        if (a >= 3)
        {
            Add_after_index(Root3, a, i);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1)
        {
            pair<Node *, Node *> kek = Split_index(Root3, r);
            pair<Node *, Node *> lol = Split_index(kek.first, l - 1);
            Root3 = Merge(lol.first, kek.second);
            run(lol.second, Root2, Root3);
        }
        else
        {
            cout << Summ(Root1, l, r) + Summ(Root2, l, r) + Summ(Root3, l, r) << "\n";
        }
    }
}