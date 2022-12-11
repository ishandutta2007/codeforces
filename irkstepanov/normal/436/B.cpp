#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> ans(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    {
        char c;
        cin >> c;
        if (c == 'U' && i % 2 == 0) ++ans[j];
        if (c == 'L' && j - i >= 0) ++ans[j - i];
        if (c == 'R' && j + i < m) ++ans[j + i];
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";

}