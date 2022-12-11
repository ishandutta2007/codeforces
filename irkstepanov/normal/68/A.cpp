#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int p[4];
    for (int i = 0; i < 4; ++i) {
        cin >> p[i];
    }

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < 4; ++i) {
        b = min(b, p[i] - 1);
    }

    cout << (a > b ? 0 : b - a + 1) << "\n";

}