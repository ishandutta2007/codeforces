#include <bits/stdc++.h>

// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\
// "We created a community that can control itself." \\
// \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ \\

// TechnoRush

using namespace std;

#define all(x) (x).begin(), (x).end()

const long long MOD = 1e9 + 7;
const long long INFLL = 1e18;
const long long INF = 1e9;
const int N = 500000;
#define int long long

int n;
int a[N];
int b[N];
map<int, int> s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        a[i] = b[i] - i;
        //cout << a[i] << "\n";
        s[a[i]] += b[i];
    }
    long long d =0 ;
    for (auto it : s)
    {
        d = max(d, it.second);
    }
    cout << d;
}