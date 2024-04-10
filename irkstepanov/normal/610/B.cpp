#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll inf = static_cast<ll>(1e18);

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<ll> a(n);
    ll x = inf;
    forn(i, n) {
        scanf("%I64d", &a[i]);
        x = min(x, a[i]);
    }

    ll ans = static_cast<ll>(n) * x;
    forn(i, n) {
        a[i] -= x;
    }

    int cntMax = 0, curr = 0;
    forn(i, n) {
        if (a[i]) {
            ++curr;
        } else {
            cntMax = max(cntMax, curr);
            curr = 0;
        }
    }
    cntMax = max(cntMax, curr);

    int A = 0, B = 0;
    forn(i, n) {
        if (a[i]) {
            ++A;
        } else {
            break;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (a[i]) {
            ++B;
        } else {
            break;
        }
    }

    cntMax = max(cntMax, A + B);
    ans += static_cast<ll>(cntMax);
    cout << ans << "\n";

}