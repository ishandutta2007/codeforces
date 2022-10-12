#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string s, t;
int nxt[26][500000];
int n;
long long ans = 0;
int last[26];

void solve()
{
    cin >> s >> t;
    int xx = 0;
    n = s.size();
    s = s + s;
    fill(last, last + 26, 2 * n);
    for (int i = 0; i < 26; i++) fill(nxt[i], nxt[i] + n, 0);
    ans = 0;
    for (int i = s.size() - 1; i >= n; i--)
    {
        last[s[i] - 'a'] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++) nxt[j][i] = last[j];
        last[s[i] - 'a'] = i;
    }
    long long pos = n - 1;
    for (int i = 0; i < t.size(); i++)
    {
        int go = nxt[t[i] - 'a'][pos];
        if (go == 2 * n)
        {
            cout << -1 << "\n";
            return;
        }
        ans += go - pos;
        go %= n;
        pos = go;
    }
    cout << (ans + n - 1) / n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}