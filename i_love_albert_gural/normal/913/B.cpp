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

    int N;
    cin >> N;

    vvi ch(N);

    for (int i = 1; i < N; i++) {
        int par;
        cin >> par;
        ch[par - 1].push_back(i);
    }

    bool spruce = true;
    for (int i = 0; i < N; i++) {
        if (ch[i].size() == 0) {
            continue;
        }

        int leaves = 0;
        for (int b : ch[i]) {
            if (ch[b].size() == 0)
                leaves++;
        }

        if (leaves < 3)
            spruce = false;
    }

    cout << (spruce ? "Yes" : "No") << "\n";

    return 0;
}