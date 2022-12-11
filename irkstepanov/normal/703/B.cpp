#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<int, ll> data;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<ll> c(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &c[i]);
        sum += c[i];
    }

    ll ans = 0;
    ll sum_cap = 0;
    vector<char> cap(n, false);
    vector<int> vct;
    while (k--) {
        int v;
        scanf("%d", &v);
        --v;
        vct.pb(v);
        cap[v] = true;
        sum_cap += c[v];
        ans += c[v] * (sum - c[v]);
    }

    ll d = 0;

    for (int v : vct) {
        d += c[v] * (sum_cap - c[v]);
    }

    ans -= d / 2;

    for (int i = 0; i < n; ++i) {
        if (!cap[i] && !cap[(i + 1) % n]) {
            ans += c[i] * c[(i + 1) % n];
        }
    }

    printf("%lld\n", ans);

}