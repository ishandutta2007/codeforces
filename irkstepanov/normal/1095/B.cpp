#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> mapa;
    while (n--) {
        int x;
        cin >> x;
        ++mapa[x];
    }

    int ans = (--mapa.end())->first - mapa.begin()->first;

    if ((--mapa.end())->second == 1) {
        ans = min(ans, (--(--mapa.end()))->first - mapa.begin()->first);
    }
    if (mapa.begin()->second == 1) {
        ans = min(ans, (--mapa.end())->first - (++mapa.begin())->first);
    }

    cout << ans << "\n";

}