#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

vector<int> cnt, t;
int c;

void upd(int pos, int val)
{
    pos += c;
    cnt[pos] += val;
    if (cnt[pos] == 1) {
        t[pos] = pos - c;
    } else {
        t[pos] = -1;
    }
    for (pos >>= 1; pos; pos >>= 1) {
        t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    vector<int> compressed = a;
    sort(all(compressed));
    compressed.resize(unique(all(compressed)) - compressed.begin());
    c = sz(compressed);

    forn(i, n) {
        a[i] = lower_bound(all(compressed), a[i]) - compressed.begin();
    }

    t.assign(2 * c, -1);
    cnt.resize(2 * c);

    forn(i, k) {
        upd(a[i], 1);
    }

    for (int i = 0; ; ++i) {
        int x = t[1];
        if (x == -1) {
            printf("Nothing\n");
        } else {
            printf("%d\n", compressed[x]);
        }
        if (i + k == n) {
            break;
        }
        upd(a[i], -1);
        upd(a[i + k], 1);
    }

}