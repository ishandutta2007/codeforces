#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

const int inf = 1000000000;
const ll mod = 1000000007;

vector <int> z_function(string s)
{
    int n = sz(s);
    vector <int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) ++z[i];
        if (z[i] + i + 1 > r)
        {
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int k = sz(s);

    vector <int> z = z_function(s);
    int cnt = n;
    int prev = -inf;

    set <int> good;
    for (int i = 1; i < k; i++)
        if (i + z[i] == k) good.insert(i);

    while (m--)
    {
        int pos;
        cin >> pos;
        --pos;
        if (pos >= prev + k)
        {
            if (pos + k - 1 < n) {cnt -= k; prev = pos; continue;}
            else {cout << "0\n"; return 0;}
        }
        else
        {
            if (!good.count(pos - prev)) {cout << "0\n"; return 0;}
            if (pos + k - 1 >= n) {cout << "0\n"; return 0;}
            cnt -= (pos - prev);
            prev = pos;
        }
    }

    ll ans = 1;
    for (int i = 0; i < cnt; i++)
        ans = (ans * 26) % mod;

    cout << ans << "\n";

}