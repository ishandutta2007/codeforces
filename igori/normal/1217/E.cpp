#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    pair<int, int> r[10];
    Node()
    {
        for (int i = 0; i < 10; i++) r[i].first = r[i].second = 1000000010;
    }
};

Node T[800000];

int n, m;
int a[250000];

pair<int, int> Merge(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
    {
        swap(a, b);
    }
    pair<int, int> res;
    res.first = a.first;
    res.second = min(b.first, a.second);
    return res;
}

pair<int, int> Get(int l, int r, int L, int R, int V, int d)
{
    if (r <= L || R <= l)
        return {1000000010, 1000000010};
    if (l <= L && R <= r)
        return T[V].r[d];
    int M = (L + R) / 2;
    return Merge(Get(l, r, L, M, 2 * V + 1, d), Get(l, r, M, R, 2 * V + 2, d));
}

void Set(int p, int L, int R, int V, int d, int x)
{
    if (p + 1 <= L || R <= p) return;
    if (p == L && p + 1 == R)
    {
        T[V].r[d].first = x;
        return;
    }
    int M = (L + R) / 2;
    Set(p, L, M, 2 * V + 1, d, x);
    Set(p, M, R, 2 * V + 2, d, x);
    T[V].r[d] = Merge(T[2 * V + 1].r[d], T[2 * V + 2].r[d]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int y = a[i];
        vector<int> digits;
        for (int j = 0; j < 10; j++)
        {
            digits.push_back(y % 10);
            y /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int j = 0; j < 10; j++)
        {
            if (digits[j] != 0)
                Set(i, 0, n, 0, j, a[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int j, x;
            cin >> j >> x;
            j--;
            vector<int> digits;
            int y = x;
            for (int i = 0; i < 10; i++)
            {
                digits.push_back(y % 10);
                y /= 10;
            }
            reverse(digits.begin(), digits.end());
            for (int i = 0; i < 10; i++)
            {
                if (digits[i] != 0)
                {
                    Set(j, 0, n, 0, i, x);
                }
                else
                {
                    Set(j, 0, n, 0, i, 1000000010);
                }
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            pair<int, int> ans = {1000000010, 1000000010};
            for (int i = 0; i < 10; i++)
            {
                pair<int, int> re = Get(l, r, 0, n, 0, i);
                if (re.second < 1000000000 && re.first + re.second < ans.first + ans.second)
                {
                    ans = re;
                }
            }
            if (ans.second >= 1000000010)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << ans.first + ans.second << "\n";
            }
        }
    }
}