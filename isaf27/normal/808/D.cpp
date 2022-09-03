#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const int BIG = 1e9;
const ll INF = 1e18;
const int M = 100001;
const int S = 10001;
const int L = 18;

int n, a[M];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    if (s % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    s /= 2;
    set<ll> q;
    ll c = 0;
    for (int i = 0; i < n; i++)
    {
        q.insert((ll)a[i]);
        c += a[i];
        if (c > s && q.find(c - s) != q.end())
        {
            cout << "YES";
            return 0;
        }
    }
    q.clear();
    c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        q.insert((ll)a[i]);
        c += a[i];
        if (c > s && q.find(c - s) != q.end())
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}