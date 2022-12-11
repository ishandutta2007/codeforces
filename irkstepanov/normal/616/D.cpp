#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
//#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int inf = (int) (1e9 + 5);
const int nmax = (int) (1e6 + 5);

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    forn(i, n) {
        scanf("%d", &a[i]);
    }

    vector<int> cnt(nmax, 0);
    cnt[a[0]] = 1;
    int diff = 1;
    int ansl = 0, ansr = 0;

    int l = 0, r = 1;
    while (r < n) {
        while (diff > k) {
            --cnt[a[l]];
            if (cnt[a[l]] == 0) {
                --diff;
            }
            ++l;
        }
        while (r < n && diff <= k) {
            ++cnt[a[r]];
            if (cnt[a[r]] == 1) {
                ++diff;
            }
            ++r;
        }
        if (diff <= k) {
            if (ansr - ansl < (r - 1) - l) {
                ansr = r - 1;
                ansl = l;
            }
        } else {
            if (ansr - ansl < (r - 2) - l) {
                ansr = r - 2;
                ansl = l;
            }
        }
    }

    printf("%d %d\n", ansl + 1, ansr + 1);

}