#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e18;

const int MAXN = 251;
const int BF = 30;
const int BIG = 1e9 + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int32_t main()
{
    #define fname "test"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout); /**/
    int n, k, m, a;
    cin >> n >> k >> m >> a;
    vector<pair<pair<int, int>, int> > arr(n);
    for (int i  = 0; i < n; i++)
        arr[i].second = i;
    vector<int> st(n, 3);
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        arr[x - 1].first.first--;
        arr[x - 1].first.second = i;
    }
    m -= a;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        auto ac = arr[i];
        ac.first.first -= m;
        if (m)
            ac.first.second = a + m;
        if (lower_bound(arr.begin(), arr.end(), ac) - arr.begin() >= k || arr[i].first.first - m == 0)
            break;
        st[arr[i].second]--;
        int M = m;
        int cnt = 0;
        for (int j = i + 1; j < n && M >= 1 + arr[j].first.first - arr[i].first.first; j++)
        {
            cnt++;
            M -= 1 + arr[j].first.first - arr[i].first.first;
        }
        if (i + cnt < k && arr[i].first.first != 0)
            st[arr[i].second]--;
    }
    for (int i = 0; i < n; i++)
        cout << st[i] << " ";
    return 0;
}