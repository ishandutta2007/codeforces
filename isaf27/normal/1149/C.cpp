#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 19);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 255;

struct Node
{
    int fmax, fmin;
    int s1, s2;
    int mx;

    Node()
    {
        fmax = 0;
        fmin = 0;
        s1 = 0;
        s2 = 0;
        mx = 0;
    }

    void upd(int x)
    {
        fmax += x;
        fmin += x;
        s1 -= x;
        s2 -= x;
    }

    Node operator+(const Node &t) const
    {
        Node ans;
        ans.fmax = max(fmax, t.fmax);
        ans.fmin = min(fmin, t.fmin);
        ans.s1 = max(s1, t.s1);
        ans.s1 = max(ans.s1, fmax - 2 * t.fmin);
        ans.s2 = max(s2, t.s2);
        ans.s2 = max(ans.s2, -2 * fmin + t.fmax);
        ans.mx = max(mx, t.mx);
        ans.mx = max(ans.mx, s1 + t.fmax);
        ans.mx = max(ans.mx, fmax + t.s2);
        return ans;
    }
};

Node tree[T];
int add[T];
int n, q, a[M];
string s;

void build(int i, int l, int r)
{
    add[i] = 0;
    if (r - l == 1)
    {
        tree[i] = Node();
        tree[i].upd(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void push(int i, int l, int r)
{
    tree[i].upd(add[i]);
    if (r - l > 1)
    {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, int x)
{
    push(i, l, r);
    if (r <= ql || qr <= l)
        return;
    if (ql <= l && r <= qr)
    {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q >> s;
    a[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a[i + 1] = a[i];
        if (s[i] == '(')
            a[i + 1]++;
        else
            a[i + 1]--;
    }
    int k = s.size() + 1;
    build(0, 0, k);
    cout << tree[0].mx << "\n";
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        upd(0, 0, k, x, k, (s[x - 1] == '(' ? -2 : 2));
        upd(0, 0, k, y, k, (s[y - 1] == '(' ? -2 : 2));
        swap(s[x - 1], s[y - 1]);
        cout << tree[0].mx << "\n";
    }
    return 0;
}