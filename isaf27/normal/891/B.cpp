#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int BIG = 2 * 1e9 + 239;
const ld pi = acos(-1.0);
const int M = 2001;
const int L = 21;
const int two = 2;
const ll INF = 1e18 + 239;
const int T = (1 << 21);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for (int i = 0; i < n - 1; i++)
        ans[v[i].second] = v[i + 1].first;
    ans[v[n - 1].second] = v[0].first;
    for (int i : ans)
        cout << i << " ";
    return 0;
}