const int N = 999999;

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct RevTree{
    vector<int> summ0, summ1, fl;
    void init(int L, int R, int V)
    {
        summ0[V] = R - L;
        if (L + 1 == R) return;
        int M = (L + R) / 2;
        init(L, M, 2 * V + 1);
        init(M, R, 2 * V + 2);
    }
    RevTree(int n)
    {
        summ0.resize(4 * n);
        summ1.resize(4 * n);
        fl.resize(4 * n);
        init(0, n, 0);
    }
    void Push(int V)
    {
        if (fl[V])
        {
            swap(summ0[2 * V + 1], summ1[2 * V + 1]);
            swap(summ0[2 * V + 2], summ1[2 * V + 2]);
            fl[2 * V + 1] ^= 1;
            fl[2 * V + 2] ^= 1;
            fl[V] = 0;
        }
    }
    void __Rev(int l, int r, int L, int R, int V)
    {
        if (r <= L || R <= l) return;
        if (l <= L && R <= r) return (void)(swap(summ0[V], summ1[V]), fl[V] ^= 1);
        int M = (L + R) / 2;
        Push(V);
        __Rev(l, r, L, M, 2 * V + 1);
        __Rev(l, r, M, R, 2 * V + 2);
        summ0[V] = summ0[2 * V + 1] + summ0[2 * V + 2];
        summ1[V] = summ1[2 * V + 1] + summ1[2 * V + 2];
    }
    void Rev(int l, int r)
    {
        __Rev(l - 1, r, 0, fl.size() / 4, 0);
    }
    int __Get(int l, int r, int L, int R, int V)
    {
        if (r <= L || R <= l) return 0;
        if (l <= L && R <= r) return summ1[V];
        int M = (L + R) / 2;
        Push(V);
        return __Get(l, r, L, M, 2 * V + 1) + __Get(l, r, M, R, 2 * V + 2);
    }
    int Get(int l, int r)
    {
        return __Get(l - 1, r, 0, fl.size() / 4, 0);
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<RevTree> tr(30, RevTree(n));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 30; j++)
        {
            if (x & (1 << j))
            {
                tr[j].Rev(i, i);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            long long ans = 0;
            int l, r;
            cin >> l >> r;
            for (int i = 0; i < 30; i++)
            {
                ans += (1ll << i) * tr[i].Get(l, r);
            }
            cout << ans << "\n";
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = 0; i < 30; i++)
            {
                if (x & (1 << i))
                {
                    tr[i].Rev(l, r);
                }
            }
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