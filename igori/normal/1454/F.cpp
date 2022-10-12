#include <bits/stdc++.h>

using namespace std;

const int N = 500000;
int H[N];

int get(int l, int r, vector<vector<int> > &sp)
{
    int j = H[r - l + 1];
    return min(sp[j][l], sp[j][r - (1 << j) + 1]);
}

int main()
{
    H[3] = 1;
    for (int i = 4; i < N; i++)
    {
        H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> pmax = a, smax = a;
        for (int i = 1; i < n; i++)
        {
            pmax[i] = max(pmax[i - 1], a[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            smax[i] = max(smax[i + 1], a[i]);
        }
        vector<vector<int> > sp(20, vector<int>(n));
        sp[0] = a;
        for (int j = 1; j < 20; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1, sp);
            }
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        int yes = 0;
        for (int i = 0; i + 1 < b.size(); i++)
        {
            int x = b[i];
            int L = -1, R = n;
            int le = 0, ri = 0;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (pmax[M] > x)
                    R = M;
                else
                    L = M;
            }
            le = R;
            L = -1, R = n;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (smax[M] > x)
                    L = M;
                else
                    R = M;
            }
            ri = L;
            assert(le <= ri);
            if (le - 2 >= 0 && a[le - 1] == x && pmax[le - 2] == x)
                le--;
            if (ri + 2 < n && a[ri + 1] == x && smax[ri + 2] == x)
                ri++;
            if (le >= 1 && ri + 1 < n)
            {
                if (pmax[le - 1] == x && smax[ri + 1] == x && get(le, ri, sp) == x)
                {
                    cout << "YES\n";
                    cout << le << " " << ri - le + 1 << " " << n - ri - 1 << "\n";
                    yes = 1;
                    break;
                }
            }
        }
        if (!yes)
        {
            int cntmx = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == b.back())
                    cntmx++;
            }
            if (cntmx >= 3)
            {
                int fl = 0;
                for (int i = 0; i < a.size(); i++)
                {
                    if (a[i] == b.back())
                        fl++;
                    if (fl == 2)
                    {
                        cout << "YES\n";
                        cout << i << " " << 1 << " " << n - i - 1 << "\n";
                        yes = 1;
                        break;
                    }
                }
            }
        }
        if (!yes)
        {
            cout << "NO\n";
        }
    }
}