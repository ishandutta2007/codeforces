#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define mt make_tuple
#define eb emplace_back

using namespace std;

typedef long long ll;

#define DR 0
#define DL 1
#define UL 2
#define UR 3

int n;
int xo[100005], yo[100005];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

vector<pair<int,int> > f[2][4];

ll ans = 0;

int par(int v) {
    return abs(v) % 2;
}

void add(int x0, int x1, int y0, int y1, int p) {
    if (par(x0) != p) x0++;
    if (par(x1) != p) x1--;
    if (par(y0) != p) y0++;
    if (par(y1) != p) y1--;

    //printf("x0=%d, x1=%d, y0=%d, y1=%d p=%d\n", x0, x1, y0, y1, p);

    int w = x0 <= x1 ? (x1 - x0 + 2) / 2 : 0;
    int h = y0 <= y1 ? (y1 - y0 + 2) / 2 : 0;
    ans += w * 1ll * h;
}

int main() {
    scanf("%d", &n);
    fo(i,0,n) {
        scanf("%d %d", xo+i, yo+i);
        fo(j,0,4) {
            int nx = xo[i] + dx[j];
            int ny = yo[i] + dy[j];
            int p = par(nx+ny);
            f[p][j].eb(nx-ny, nx+ny);
        }
    }
    fo(p,0,2) {
        vector<int> xs;
        fo(j,0,4) {
            for (auto pt : f[p][j]) {
                xs.push_back(pt.first);
            }
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(),xs.end())-xs.begin());
        vector<int> bf[4];
        fo(j,0,4) bf[j].resize(sz(xs));
        fo(j,0,4) fo(i,0,sz(xs)) {
            bf[j][i] = j < 2 ? -2e9 : 2e9;
        }
        fo(j,0,4) for (auto pt : f[p][j]) {
            int x = pt.first, y = pt.second;
            int xi = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            if (j < 2) bf[j][xi] = max(bf[j][xi], y);
            else bf[j][xi] = min(bf[j][xi], y);
        }
        fo(i,1,sz(xs)) {
            bf[0][i] = max(bf[0][i], bf[0][i-1]);
            bf[3][i] = min(bf[3][i], bf[3][i-1]);
        }
        for (int i = sz(xs) - 2; i >= 0; i--) {
            bf[1][i] = max(bf[1][i], bf[1][i+1]);
            bf[2][i] = min(bf[2][i], bf[2][i+1]);
        }
        fo(i,0,sz(xs)) {
            int mn = max(bf[UR][i], bf[UL][i]);
            int mx = min(bf[DR][i], bf[DL][i]);
            //printf("xs[%d]=%d, mn=%d, mx=%d, p=%d\n", i, xs[i], mn, mx, p);
            add(xs[i], xs[i], mn, mx, p);
            if (i+1 < sz(xs) && xs[i]+1 != xs[i+1]) {
                mn = max(bf[UR][i], bf[UL][i+1]);
                mx = min(bf[DR][i], bf[DL][i+1]);
                add(xs[i]+1, xs[i+1]-1, mn, mx, p);
            }
        }
    }
    printf("%lld\n", ans);
}