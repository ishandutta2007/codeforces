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

    vector<bool> member(2000);

    int f1 = 1, f2 = 1;
    member[1] = true;

    while (f2 < 2000) {
        member[f2] = true;
        int tmp = f1 + f2;
        f1 = f2;
        f2 = tmp;
    }

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << (member[i] ? 'O' : 'o');
    }
    cout << endl;

    return 0;
}