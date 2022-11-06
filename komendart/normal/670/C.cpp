#include <iostream>
#include <unordered_map>

#define s second
#define f first
#define pb push_back
#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define len(a) (int)(a).size()
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///freopen(".in", "r", stdin);
    ///freopen(".out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<int, int> l;
    forn(i, n) {
        int x;
        cin >> x;
        if (l.find(x) == l.end()) {
            l[x] = 1;
        }
        else {
            l[x] ++;
        }
    }
    int m;
    cin >> m;
    int ma1 = -1, ma2 = -1, mai;
    vector<int> b(m), c(m);
    forn(i, m) cin >> b[i];
    forn(i, m) cin >> c[i];
    forn(i, m) {
        int b1 = 0, c1 = 0;
        if (l.find(b[i]) != l.end())
            b1 = l[b[i]];
        if (l.find(c[i]) != l.end())
            c1 = l[c[i]];
        if (b1 > ma1 || b1 == ma1 && c1 > ma2) {
            ma1 = b1;
            ma2 = c1;
            mai = i + 1;
        }
    }
    cout << mai;
    return 0;
}