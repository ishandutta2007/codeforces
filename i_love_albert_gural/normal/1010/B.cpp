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

    int M, N;
    cin >> M >> N;

    vector<bool> lie(N);

    for (int i = 0; i < N; i++) {
        cout << i + 1 << endl;
        int resp;
        cin >> resp;

        if (!resp) return 0;
        if (resp == -1) lie[i] = true;
    }

    int lo = N + 1, hi = M;
    for (int inx = 0; ; inx = (inx + 1) % N) {
        int mi = (lo + hi) / 2;
        cout << mi << endl;
        int resp;
        cin >> resp;

        if (!resp) return 0;
        bool higher = (resp == 1) ^ lie[inx];
        if (higher) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    return 0;
}