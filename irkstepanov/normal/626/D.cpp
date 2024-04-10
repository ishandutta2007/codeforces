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
typedef pair<int, int> edge;

const int amax = 5000 + 10;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    vector<ll> f(amax);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ++f[a[j] - a[i]];
        }
    }

    vector<ll> fnew(2 * amax);
    for (int d = 2; d < 2 * amax; ++d) {
        for (int x = 1; x < d && x < amax; ++x) {
            fnew[d] += f[x] * f[d - x];
        }
    }

    ll ans = 0;
    ll sum = 0;
    for (int i = amax - 1; i >= 2; --i) {
        sum += f[i];
    }
    for (int d = 2; d < amax; ++d) {
        sum -= f[d];
        ans += fnew[d] * sum;
    }

    ll c = n * (n - 1) / 2;
    ld answer = (ld)(ans) / (ld)(c);
    answer /= (ld)(c);
    answer /= (ld)(c);

    cout << fixed;
    cout.precision(10);
    cout << answer << "\n";

}