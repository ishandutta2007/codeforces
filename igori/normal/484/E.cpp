#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <bitset>
#include <map>

typedef long long ll;

using namespace std;

#define all(x) x.begin(), x.end()
const long long INF = 1e9;

ll n, m;
int w;
ll a[500000];
map<int, int> sh;
vector<int> f;
ll b[500000];
vector<int> pos[500000];

struct Node{
    int L, R;
    pair<int, pair<int, int> > r;
    Node * Ls;
    Node * Rs;
};

vector<Node * > trees;

const int H = 10;

inline int GetNum()
{
    int a = 0;
    char c = getchar();
    while ('0' <= c && c <= '9')
    {
        a = a * H + c - '0';
        c = getchar();
        if ('0' > c || c > '9')
            break;
    }
    return a;
}

inline pair<int, pair<int, int> > merges(pair<int, pair<int, int> > r1, pair<int, pair<int, int> > r2, int len1, int len2)
{
    pair<int, pair<int, int> > r;
    r.first = max(max(r1.first, r2.first), r1.second.second + r2.second.first);
    r.second.first = r1.second.first;
    if (r1.second.first == len1)
        r.second.first += r2.second.first;
    r.second.second = r2.second.second;
    if (r2.second.second == len2)
        r.second.second += r1.second.second;
    return r;
}

inline void build(int L, int R, Node * Nd)
{
    if (L + 1 == R)
    {
        Nd->L = L;
        Nd->R = R;
        Nd->r = {1, {1, 1}};
        return;
    }
    int M = (L + R) / 2;
    Nd->Ls = new Node();
    Nd->Rs = new Node();
    build(L, M, Nd->Ls);
    build(M, R, Nd->Rs);
    Nd->L = L;
    Nd->R = R;
    Nd->r = merges(Nd->Ls->r, Nd->Rs->r, M - L, R - M);
}

inline Node * rebuild(int p, Node * Nd)
{
    //cout << p << " " << Nd->L << " " << Nd->R << endl;
    if (Nd->L + 1 == Nd->R)
    {
        //cout << "? " << endl;
        Nd->r = {0, {0, 0}};
        return Nd;
    }
    int M = (Nd->L + Nd->R) / 2;
    if (p < M)
    {
        Node * CNode = new Node();
        *CNode = *Nd->Ls;
        Nd->Ls = rebuild(p, CNode);
    }
    else
    {
        Node * CNode = new Node();
        *CNode = *Nd->Rs;
        Nd->Rs = rebuild(p, CNode);
    }
    //cout << "G" << endl;
    Nd->r = merges(Nd->Ls->r, Nd->Rs->r, M - Nd->L, Nd->R - M);
    //cout << "G" << endl;
    return Nd;
}

inline pair<int, pair<int, int> > get(int l, int r, Node * Nd)
{
    int L = Nd->L;
    int R = Nd->R;
    if (r <= L || R <= l)
        return {0, {0, 0}};
    if (l <= L && R <= r)
    {
        return Nd->r;
    }
    int M = (L + R) / 2;
    return merges(get(l, r, Nd->Ls), get(l, r, Nd->Rs), M - L, R - M);
}

inline int ok(int Num, int l, int r)
{
    return get(l, r, trees[Num]).first >= w;
}

int ans(int l, int r)
{
    int L = 0, R = trees.size();
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        //cout << M << " : " << ok(M, l, r + 1, w) << endl;
        if (ok(M, l, r + 1))
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return L;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("rollback.in", "r", stdin);
    //freopen("rollback.out", "w", stdout);
    n = GetNum();
    Node * Mroot = new Node();
    trees.push_back(Mroot);
    build(0, n, Mroot);
    for (int i = 0; i < n; i++)
    {
        a[i] = GetNum();
        f.push_back(a[i]);
    }
    sort(f.begin(), f.end());
    f.resize(unique(f.begin(), f.end()) - f.begin());
    for (int i = 0; i < f.size(); i++)
    {
        sh[f[i]] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = sh[a[i]];
        pos[b[i]].push_back(i);
    }

    for (int i = 0; i < f.size(); i++)
    {
        Node * Nroot = new Node();
        *Nroot = *trees[trees.size() - 1];
        for (int j = 0; j < pos[i + 1].size(); j++)
        {
            int rg = pos[i + 1][j];
            Nroot = rebuild(pos[i + 1][j], Nroot);
        }
        trees.push_back(Nroot);
    }

    m = GetNum();
    while (m--)
    {
        int l, r;
        l = GetNum();
        r = GetNum();
        w = GetNum();
        l--;
        r--;
        int ex = ans(l, r);
        printf("%d ", f[ex]);
    }
}