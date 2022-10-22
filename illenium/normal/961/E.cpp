#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int bit[MAXN], a[MAXN], n;
vector<int> v[MAXN];

inline int lowbit(int x) { return x & -x; }

inline void add(int i, int x)
{
    while (i <= n) { bit[i] += x; i += lowbit(i); }
}

inline int sum(int i)
{
    int ans = 0;
    while (i) { ans += bit[i]; i -= lowbit(i); }
    return ans;
}

int main()
{
    while (cin >> n) 
    {
        memset(bit, 0, sizeof bit);
        for (int i = 1; i < MAXN; i++) v[i].clear();
        for (int i = 1; i <= n; i++) 
        { 
            cin >> a[i];
            add(i, 1);
            if (a[i] < MAXN) v[a[i]].push_back(i);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = sum(min(a[i], n)) - sum(i);
            if (tmp > 0) ans += tmp;
            for (int j = 0; j < v[i].size(); j++) add(v[i][j], -1);
        }
        cout << ans << endl;
    }
    return 0;
}