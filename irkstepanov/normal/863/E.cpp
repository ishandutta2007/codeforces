#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

struct node {
    int promise;
    int minn;
    node() : promise(0), minn(0) {}
};

vector<node> t;

void push(int v) {
    t[v * 2].promise += t[v].promise;
    t[v * 2].minn += t[v].promise;
    t[v * 2 + 1].promise += t[v].promise;
    t[v * 2 + 1].minn += t[v].promise;
    t[v].promise = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        t[v].promise += 1;
        t[v].minn += 1;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
}

int get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v].minn;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    int ans = 100500;
    if (l <= tm) {
        ans = min(ans, get(v * 2, tl, tm, l, min(r, tm)));
    }
    if (r > tm) {
        ans = min(ans, get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    return ans;
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    vector<int> sorted;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        sorted.pb(l[i]);
        sorted.pb(r[i]);
        sorted.pb(r[i] + 1);
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    int N = sz(sorted);
    t.resize(4 * N);
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(all(sorted), l[i]) - sorted.begin();
        r[i] = lower_bound(all(sorted), r[i]) - sorted.begin();
        update(1, 0, N - 1, l[i], r[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (get(1, 0, N - 1, l[i], r[i]) > 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";

}