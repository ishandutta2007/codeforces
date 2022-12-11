#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

struct query
{
    int x, y;
    char type;
};

int x, y;
vector<int> tx, ty;

void updatex(int l, int r, int val)
{
    for (l += x, r += x; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            tx[l] = max(tx[l], val);
        }
        if (!(r & 1)) {
            tx[r] = max(tx[r], val);
        }
    }
}

void updatey(int l, int r, int val)
{
    for (l += y, r += y; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ty[l] = max(ty[l], val);
        }
        if (!(r & 1)) {
            ty[r] = max(ty[r], val);
        }
    }
}

int getx(int pos)
{
    pos += x;
    int ans = tx[pos];
    for (pos >>= 1; pos; pos >>= 1) {
        ans = max(ans, tx[pos]);
    }
    return ans;
}

int gety(int pos)
{
    pos += y;
    int ans = ty[pos];
    for (pos >>= 1; pos; pos >>= 1) {
        ans = max(ans, ty[pos]);
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, q;
    cin >> n >> q;

    vector<query> v(q);
    vector<int> sortedx, sortedy;
    forn(i, q) {
        cin >> v[i].y >> v[i].x >> v[i].type;
        --v[i].x, --v[i].y;
        sortedx.pb(v[i].x);
        sortedy.pb(v[i].y);
    }

    sort(all(sortedx));
    sort(all(sortedy));
    sortedx.resize(unique(all(sortedx)) - sortedx.begin());
    sortedy.resize(unique(all(sortedy)) - sortedy.begin());

    forn(i, q) {
        v[i].x = lower_bound(all(sortedx), v[i].x) - sortedx.begin();
        v[i].y = lower_bound(all(sortedy), v[i].y) - sortedy.begin();
    }

    x = sz(sortedx), y = sz(sortedy);
    tx.assign(2 * x, -1), ty.assign(2 * y, -1);

    forn(i, q) {
        //cout << v[i].x << " " << v[i].y << "\n";
        if (v[i].type == 'L') {
            int p = getx(v[i].x);
            if (p == -1) {
                printf("%d\n", sortedy[v[i].y] + 1);
                updatex(v[i].x, v[i].x, v[i].y);
                updatey(0, v[i].y, v[i].x);
            } else {
                printf("%d\n", sortedy[v[i].y] - sortedy[p]);
                updatex(v[i].x, v[i].x, v[i].y);
                updatey(p + 1, v[i].y, v[i].x);
            }
        } else {
            int p = gety(v[i].y);
            if (p == -1) {
                printf("%d\n", sortedx[v[i].x] + 1);
                updatey(v[i].y, v[i].y, v[i].x);
                updatex(0, v[i].x, v[i].y);
            } else {
                printf("%d\n", sortedx[v[i].x] - sortedx[p]);
                updatey(v[i].y, v[i].y, v[i].x);
                updatex(p + 1, v[i].x, v[i].y);
            }
        }
    }

}