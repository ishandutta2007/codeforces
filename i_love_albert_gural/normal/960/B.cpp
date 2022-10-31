#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K1, K2;
    cin >> N >> K1 >> K2;

    vi a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];

    vi d(N);
    for (int i = 0; i < N; i++) {
        d[i] = abs(a[i] - b[i]);
    }

    for (int m = 0; m < K1 + K2; m++) {
        int inx = 0;
        for (int i = 1; i < N; i++) {
            if (d[i] > d[inx])
                inx = i;
        }

        if (d[inx]) {
            d[inx]--;
        } else {
            d[inx]++;
        }
    }

    ll ans = 0;
    for (int v : d)
        ans += v * 1ll * v;
    cout << ans << endl;

    return 0;
}