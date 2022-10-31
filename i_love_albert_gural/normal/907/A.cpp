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

bool likes(int bear, int car) {
    return bear <= car && 2 * bear >= car;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int V1, V2, V3, VM;
    cin >> V1 >> V2 >> V3 >> VM;

    for (int C = 1; C <= 200; C++) {
        for (int B = C + 1; B <= 200; B++) {
            for (int A = B + 1; A <= 200; A++) {
                if (VM <= C && likes(V1, A) && likes(V2, B) && likes(V3, C)
                        && !likes(VM, A) && !likes(VM, B) && likes(VM, C)) {
                    cout << A << endl << B << endl << C << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}