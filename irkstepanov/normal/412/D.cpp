#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int maxn = 50000;

int main()
{

    int n;
    cin >> n;

    int ans[maxn];
    for (int i = 1; i <= n; i++)
        ans[i] = i;

    set <int> para[maxn];
    int m;
    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        para[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
    {
        int pos = i, x = ans[i];
        while (pos > 1 && para[x].count(ans[pos - 1]))
        {
            swap(ans[pos], ans[pos - 1]);
            --pos;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

}