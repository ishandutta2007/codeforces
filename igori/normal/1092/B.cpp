#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

typedef long long ll;

struct Node {
    ll key, pri;
    ll other_data;
    Node * L, * R;
    //other stuff
    int cnt;
};

void create(Node * A, int x)
{
    A->key = x;
    A->pri = (rand() << 15) + rand();
    A->cnt = 1;
}

void create_root(Node * A, int x)
{
    A->key = x;
    A->pri = 0;
}

int Find(int x, Node * Scope)
{
    if (Scope == nullptr) return 0;
    if (Scope->key == x)
    {
        return 1;
    }
    if (x < Scope->key)
    {
        return Find(x, Scope->L);
    }
    else
    {
        return Find(x, Scope->R);
    }
}

pair<Node *, Node *> Split(int key, Node * Scope)
{
    if (Scope == nullptr) return {nullptr, nullptr};
    if (Scope->key <= key)
    {
        pair<Node *, Node *> kek = Split(key, Scope->R);
        Scope->R = kek.first;
        return {Scope, kek.second};
    }
    else
    {
        if (Scope->L == nullptr) return {nullptr, Scope};
        pair<Node *, Node *> kek = Split(key, Scope->L);
        Scope->L = kek.second;
        return {kek.first, Scope};
    }
}

Node * Merge(Node * L, Node * R)
{
    if (L == nullptr) return R;
    if (R == nullptr) return L;
    if (L->pri < R->pri)
    {
        L->R = Merge(L->R, R);
        return L;
    }
    else
    {
        R->L = Merge(L, R->L);
        return R;
    }
}

void del(Node *& Root, int x)
{
    pair<Node *, Node *> kek = Split(x, Root);
    Root = Merge(Split(x - 1, kek.first).first, kek.second);
}

void add(Node *& Root, int x)
{
    if (Find(x, Root) == 1)
    {
        del(Root, x);
        return;
    }
    Node * kek = new Node();
    create(kek, x);
    pair<Node *, Node *> lol = Split(x, Root);
    lol.first = Merge(lol.first, kek);
    Root = Merge(lol.first, lol.second);
}

vector<int> res;

void Printer(Node * Nd)
{
    if (Nd == nullptr) return;
    Printer(Nd->L);
    res.push_back(Nd->key);
    Printer(Nd->R);
}

signed main()
{
    srand(time(NULL));
    Node * Root = nullptr;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        add(Root, x);
    }
    Printer(Root);
    ll ans = 0;
    for (int i = 0; i + 1 < res.size(); i += 2)
    {
        ans += res[i + 1] - res[i];
    }
    cout << ans;
}