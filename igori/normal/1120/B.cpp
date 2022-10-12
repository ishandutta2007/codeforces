#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#define td typedef
td long long ll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) x.begin(), x.end()

const long long INFLL = 4e18;
const long long INF = 1e9;

using namespace std;
const int MOD = 1e9 + 7;
ll n;
ll a[500001];
ll b[500001];
ll A[500001];
ll delta[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
        A[i] = a[i];
    }
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        b[i] = s[i] - '0';
    }
    long long op = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        long long value = b[i] - a[i];
        delta[i] = value;
        a[i] += value;
        a[i + 1] += value;
        op += abs(value);
        //cout << delta[i] << " ";
    }
    //cout << endl;
    if (a[n - 1] != b[n - 1])
    {
        cout << -1;
        return 0;
    }
    cout << op << endl;
    set<pair<int, int> > can;
    for (int i = 0; i + 1 < n; i++)
    {
        if (delta[i] > 0)
        {
            if (A[i] + 1 <= 9 && A[i + 1] + 1 <= 9)
                can.insert({i, 1});
        }
        if (delta[i] < 0)
        {
            if (A[i] - 1 >= 0 && A[i + 1] - 1 >= 0)
                can.insert({i, -1});
        }
    }
    for (int i = 0; i < min(100000LL, op); i++)
    {
        auto it = can.begin();
        pair<ll, ll> c = *it;
        cout << c.first + 1 << " " << c.second << "\n";
        can.erase(it);
        A[c.first] += c.second;
        A[c.first + 1] += c.second;
        delta[c.first] -= c.second;
        for (int j = max(c.first - 1, 0LL); j <= min(n - 1, c.first + 1); j++)
        {
            if (delta[j] > 0)
            {
                if (A[j] + 1 <= 9 && A[j + 1] + 1 <= 9)
                    can.insert({j, 1});
            }
            if (delta[j] < 0)
            {
                if (A[j] - 1 >= 0 && A[j + 1] - 1 >= 0)
                    can.insert({j, -1});
            }
        }
    }
}