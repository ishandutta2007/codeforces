#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> t;

void update(int pos, int val)
{
    pos += N;
    t[pos] = max(t[pos], val);
    for (pos >>= 1; pos; pos >>= 1) {
        t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    }
}

int get(int l, int r)
{
    int ans = 0;
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans = max(ans, t[l]);
        }
        if (!(r & 1)) {
            ans = max(ans, t[r]);
        }
    }
    return ans;
}

struct dama
{
    int a, b, c;
    bool operator<(const dama& other) const
    {
        return a < other.a;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<dama> v(n);
    vector<int> sorted(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].a);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].b);
        sorted[i] = v[i].b;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].c);
    }

    sort(all(v));
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    N = sz(sorted);
    t.resize(2 * N);

    int prev = n - 1;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1 && v[i].a != v[i + 1].a) {
            for (int j = i + 1; j <= prev; ++j) {
                int pos = lower_bound(all(sorted), v[j].b) - sorted.begin();
                update(pos, v[j].c);
            }
            prev = i;
        }
        int pos = lower_bound(all(sorted), v[i].b) - sorted.begin();
        int x = get(pos + 1, N - 1);
        if (x > v[i].c) {
            ++ans;
        }
    }

    cout << ans << "\n";

}