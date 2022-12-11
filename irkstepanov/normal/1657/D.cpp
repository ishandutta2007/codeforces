#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");


    int n;
    ll C;
    cin >> n >> C;
    vector<ll> maxx(C + 1);
    vector<ll> prod(C + 1, 0);
    for (int i = 0; i < n; ++i) {
        ll c, d, h;
        cin >> c >> d >> h;
        prod[c] = max(prod[c], d * h);
    }
    for (int c = 1; c <= C; ++c) {
        for (int i = 1; c * i <= C; ++i) {
            maxx[c * i] = max(maxx[c * i], prod[c] * i);
        }
    }
    for (int i = 1; i <= C; ++i) {
        maxx[i] = max(maxx[i], maxx[i - 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        ll D, H;
        cin >> D >> H;
        if (maxx[C] <= D * H) {
            cout << "-1 ";
        } else {
            int lf = 0, rg = C;
            while (rg - lf > 1) {
                int pos = (lf + rg) >> 1;
                if (maxx[pos] > D * H) {
                    rg = pos;
                } else {
                    lf = pos;
                }
            }
            cout << rg << " ";
        }
    }
    cout << "\n";


}