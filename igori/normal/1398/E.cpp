const int LG = 21;
const int N =208;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

set<int> fire, light;

struct Node{
    int y;
    int we;
    ll summ;
    int cnt;
    Node *L, *R;
};

void create(Node * Nd, int x)
{
    Nd->y = (rand() << 15) + rand();
    Nd->we = x;
    Nd->summ = x;
    Nd->cnt = 1;
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

void update(Node * Nd)
{
    Nd->summ = Nd->we + get_summ(Nd->L) + get_summ(Nd->R);
    Nd->cnt = 1 + get_cnt(Nd->L) + get_cnt(Nd->R);
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

pair<Node *, Node *> Split(Node * Scope, int k)
{
    if (!Scope) return {nullptr, nullptr};
    if (Scope->we >= k)
    {
        pair<Node *, Node *> kek = Split(Scope->R, k);
        Scope->R = kek.first;
        update(Scope);
        return {Scope, kek.second};
    }
    else
    {
        pair<Node *, Node *> kek = Split(Scope->L, k);
        Scope->L = kek.second;
        update(Scope);
        return {kek.first, Scope};
    }
}

pair<Node *, Node *> Split_size(Node * Scope, int k)
{
    if (!Scope) return {nullptr, nullptr};
    if (get_cnt(Scope->L) < k)
    {
        pair<Node *, Node *> kek = Split_size(Scope->R, k - get_cnt(Scope->L) - 1);
        Scope->R = kek.first;
        update(Scope);
        return {Scope, kek.second};
    }
    else
    {
        pair<Node *, Node *> kek = Split_size(Scope->L, k);
        Scope->L = kek.second;
        update(Scope);
        return {kek.first, Scope};
    }
}

void Insert(int x, Node *& Root)
{
    pair<Node *, Node *> S = Split(Root, x);
    Node * Nd = new Node();
    create(Nd, x);
    S.first = Merge(S.first, Nd);
    Root = Merge(S.first, S.second);
}

void Erase(int x, Node *& Root)
{
    pair<Node *, Node *> S = Split(Root, x);
    Root = Merge(Split(S.first, x + 1).first, S.second);
}

long long summ_of_top_k(int k, Node *& Root)
{
    if (k > get_cnt(Root)) return get_summ(Root);
    pair<Node *, Node *> S = Split_size(Root, k);
    ll x = get_summ(S.first);
    Root = Merge(S.first, S.second);
    return x;
}

void Declare(Node * Nd)
{
    if (Nd)
    {
        Declare(Nd->L);
        cout << Nd->we << " ";
        Declare(Nd->R);
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node * Root = nullptr;
    int n;
    cin >> n;
    ll sum = 0;
    while (n--)
    {
        int t, d;
        cin >> t >> d;
        sum += d;
        if (t == 0)
        {
            if (d > 0)
            {
                fire.insert(d);
                Insert(d, Root);
            }
            else
            {
                fire.erase(-d);
                Erase(-d, Root);
            }
        }
        else
        {
            if (d > 0)
            {
                light.insert(d);
                Insert(d, Root);
            }
            else
            {
                light.erase(-d);
                Erase(-d, Root);
            }
        }
        if (light.size() == 0)
        {
            cout << sum << "\n";
        }
        else
        {
            int C = light.size();
            int minl = *(light.begin());
            ll add = summ_of_top_k(C, Root);
            if (fire.size() == 0)
            {
                add -= minl;
            }
            else
            {
                auto it = fire.end();
                it--;
                int maxf = *it;
                if (maxf < minl)
                    add += maxf - minl;
            }
            cout << add + sum << "\n";
        }
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/