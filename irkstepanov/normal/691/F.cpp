#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int amax = 3e6 + 5;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<ll> cnt(amax);
    while (n--) {
        int a;
        scanf("%d", &a);
        ++cnt[a];
    }

    vector<ll> suff_sum(amax);
    suff_sum[amax - 1] = cnt[amax - 1];
    for (int i = amax - 2; i >= 0; --i) {
        suff_sum[i] = suff_sum[i + 1] + cnt[i];
    }

    vector<ll> ans(amax);
    ll inf = 0;
    for (int a = 1; a < amax; ++a) {
        int b;
        for (b = 1; a * b < amax; ++b) {
            if (a != b) {
                ans[a * b] += cnt[a] * cnt[b];
            } else {
                ans[a * b] += cnt[a] * (cnt[a] - 1);
            }
        }
        if (b != amax) {
            if (a < b) {
                inf += cnt[a] * suff_sum[b];
            } else {
                inf += cnt[a] * (suff_sum[b] - 1);
            }
        }
    }

    vector<ll> sum(amax);
    sum[amax - 1] = ans[amax - 1];
    for (int i = amax - 2; i >= 0; --i) {
        sum[i] = sum[i + 1] + ans[i];
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int p;
        scanf("%d", &p);
        printf("%I64d\n", sum[p] + inf);
    }

}