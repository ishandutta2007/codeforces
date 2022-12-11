#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, p;
    cin >> n >> p;

    vector<ld> prob(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        int cnt = r / p - (l - 1) / p;
        prob[i] = (ld)(cnt) / (ld)(r - l + 1);
    }

    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ld a = prob[(i - 1 + n) % n];
        ld b = prob[i];
        ld c = prob[(i + 1) % n];
        ld d = 2 * b + (1 - b) * (a + c);
        ans += d * 1000;
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << "\n";

}