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

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int str = 0;
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '*')
                str = 0;
            else 
                str++;
            if (str >= K)
                ans++;
        }
    }

    if (K != 1) {
        for (int j = 0; j < M; j++) {
            int str = 0;
            for (int i = 0; i < N; i++) {
                if (grid[i][j] == '*')
                    str = 0;
                else 
                    str++;
                if (str >= K)
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}