#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int M = 3 * 1e5 + 1;
const int BIG = 2 * 1e9 + 1;
const ll INF = 2 * 1e18;
const ll MOD = 1e9 + 7;
const int two = 2;
const int four = 4;
const ld pi = acos(-1.0);
const ld eps = 1e-5;

int n, p[M], ans[M];
vector<int> mx[M];

int main()
{
    #ifndef ONLINE_JUDGE
    //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    mx[0] = {p[0]};
    memset(ans, 0, sizeof(ans));
    ans[p[0] - 1]--;
    for (int i = 1; i < n; i++)
    {
        mx[i] = mx[i - 1];
        if (p[i] > mx[i][0])
            ans[p[i] - 1]--;
        if (mx[i].size() >= 2)
        {
            if (p[i] > mx[i][1] && p[i] < mx[i][0])
                ans[mx[i][0] - 1]++;
        }
        else if (p[i] < mx[i][0])
            ans[mx[i][0] - 1]++;
        mx[i].push_back(p[i]);
        sort(mx[i].rbegin(), mx[i].rend());
        if (mx[i].size() == 3)
            mx[i].pop_back();
    }
    int r = 0;
    for (int i = 1; i < n; i++)
        if (ans[i] > ans[r])
            r = i;
    cout << r + 1;
    return 0;
}