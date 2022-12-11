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
typedef pair<ll, ll> pll;

bool intersect(int a, int b, int c, int d)
{
    if (b <= c) {
        return false;
    }
    if (a >= d) {
        return false;
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }

    vector<int> cnt(n);
    int bad = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersect(l[i], r[i], l[j], r[j])) {
                ++bad;
                ++cnt[i], ++cnt[j];
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == bad) {
            ans.pb(i);
        }
    }

    printf("%d\n", sz(ans));
    for (int x : ans) {
        printf("%d ", x + 1);
    }
    printf("\n");

}