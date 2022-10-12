#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5;

int tree[4 * N];

void Set(int pos, int x, int L = 0, int R = N, int V = 0)
{
    if (L + 1 == R)
    {
        tree[V] = x;
        return;
    }
    int M = (L + R) / 2;
    if (pos < M) Set(pos, x, L, M, 2 * V + 1);
    else Set(pos, x, M, R, 2 * V + 2);
    tree[V] = min(tree[2 * V + 1], tree[2 * V + 2]);
}

int Arg_smaller(int x, int L = 0, int R = N, int V = 0)
{
    if (tree[V] >= x) return N;
    if (L + 1 == R) return L;
    int M = (L + R) / 2;
    int a = Arg_smaller(x, L, M, 2 * V + 1);
    if (a != N) return a;
    return Arg_smaller(x, M, R, 2 * V + 2);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    vector<int> lst(n + 1);
    vector<int> L(n + 1), R(n + 1), T(n + 1);

    struct Rect{
        int x1, y1, x2, y2;
    };

    vector<vector<Rect> > s(n + 1);
    vector<vector<ll> > sq(n + 1, vector<ll>(1));
    vector<vector<ll> > dn(n + 1, vector<ll>(1));
    vector<vector<int> > len(n + 1, vector<int>(1));

    for (int i = 1; i <= n; i++)
    {
        int a, l, r, k;
        cin >> a >> l >> r >> k;
        a = (a + ans) % (n + 1);
        l = (l + ans) % i + 1;
        r = (r + ans) % i + 1;
        if (l > r) swap(l, r);
        k = (k + ans) % (n + 1);

        Set(a, i), lst[a] = i;

        if (L[a] != 0)
        {
            int le = L[a], ri = R[a];
            s[a].push_back({T[a], le, i - 1, ri});
            sq[a].push_back(sq[a].back() + 1ll * (i - T[a]) * (R[a] - L[a] + 1));
            dn[a].push_back(dn[a].back() + 1ll * (i - T[a]) * R[a]);
            len[a].push_back(len[a].back() + i - T[a]);
            L[a] = 0, R[a] = 0, T[a] = 0;

            int nmex = Arg_smaller(ri);
            for (int x = nmex; ;)
            {
                int pos = lst[x];
                if (L[x] != 0)
                {
                    if (R[x] == ri) break;
                    s[x].push_back({T[x], L[x], i - 1, R[x]});
                    sq[x].push_back(sq[x].back() + 1ll * (i - T[x]) * (R[x] - L[x] + 1));
                    dn[x].push_back(dn[x].back() + 1ll * (i - T[x]) * R[x]);
                    len[x].push_back(len[x].back() + i - T[x]);
                }
                else
                {
                    L[x] = pos + 1;
                }
                R[x] = ri, T[x] = i;
                ri = pos;
                if (pos == 0) break;
                x = Arg_smaller(ri);
            }
        }

        if (a == 0)
        {
            if (L[1] == 0)
            {
                L[1] = i, R[1] = i, T[1] = i;
            }
            else
            {
                s[1].push_back({T[1], L[1], i - 1, R[1]});
                sq[1].push_back(sq[1].back() + 1ll * (i - T[1]) * (R[1] - L[1] + 1));
                dn[1].push_back(dn[1].back() + 1ll * (i - T[1]) * R[1]);
                len[1].push_back(len[1].back() + i - T[1]);
                T[1] = i;
                R[1]++;
            }
        }
        else
        {
            if (L[0] == 0)
            {
                L[0] = i, R[0] = i, T[0] = i;
            }
            else
            {
                s[0].push_back({T[0], L[0], i - 1, R[0]});
                sq[0].push_back(sq[0].back() + 1ll * (i - T[0]) * (R[0] - L[0] + 1));
                dn[0].push_back(dn[0].back() + 1ll * (i - T[0]) * R[0]);
                len[0].push_back(len[0].back() + i - T[0]);
                T[0] = i;
                R[0]++;
            }
        }
        ans = 0;
        if (L[k] != 0)
            ans += 1ll * max(0, min(R[k], r) - max(L[k], l) + 1) * max(0, r - max(l, T[k]) + 1);
        int L = 0, R = s[k].size();
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            if (s[k][M].x2 >= l && s[k][M].y2 >= l) R = M;
            else L = M;
        }
        if (L < s[k].size())
            ans += 1ll * max(0, min(r, s[k][L].y2) - max(l, s[k][L].y1) + 1) * max(0, min(r, s[k][L].x2) - max(l, s[k][L].x1) + 1);
        L++;
        if (L < s[k].size())
        {
            int L2 = L, R2 = s[k].size();
            while (L2 + 1 < R2)
            {
                int M2 = (L2 + R2) / 2;
                if (s[k][M2].x1 <= r) L2 = M2;
                else R2 = M2;
            }
            if (L2 < s[k].size())
                ans += 1ll * max(0, min(r, s[k][L2].y2) - max(l, s[k][L2].y1) + 1) * max(0, min(r, s[k][L2].x2) - max(l, s[k][L2].x1) + 1);
            if (L < L2)
            {
                int L3 = L - 1, R3 = L2;
                while (L3 + 1 < R3)
                {
                    int M3 = (L3 + R3) / 2;
                    if (s[k][M3].y1 >= l) R3 = M3;
                    else L3 = M3;
                }
                ans += sq[k][L2] - sq[k][R3];
                ans += dn[k][R3] - dn[k][L];
                ans -= 1ll * (len[k][R3] - len[k][L]) * (l - 1);
            }
        }
        cout << ans << "\n";
    }
}