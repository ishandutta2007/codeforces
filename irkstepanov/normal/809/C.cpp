#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const ll r2 = (mod + 1) / 2;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

const int rmax = 33;

ll sum[2][2][2][rmax];
ll cnt[2][2][2][rmax];

bool bit(ll mask, int pos)
{
    return (mask >> pos) & 1;
}

vector<ll> degs(50);

ll solve(ll xmax, ll ymax, ll k)
{
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    sum[1][1][1][0] = 0;
    cnt[1][1][1][0] = 1;

    for (int r = 1; r < rmax; ++r) {
        int pos = rmax - r - 1;
        for (int a = 0; a < 2; ++a) {
            int dx = 1;
            if (a == 0 || bit(xmax, pos)) {
                dx = 2;
            }
            for (int b = 0; b < 2; ++b) {
                int dy = 1;
                if (b == 0 || bit(ymax, pos)) {
                    dy = 2;
                }
                for (int c = 0; c < 2; ++c) {
                    for (int xx = 0; xx < dx; ++xx) {
                        int newX = 0;
                        if (a == 1 && xx == bit(xmax, pos)) {
                            newX = 1;
                        }
                        for (int yy = 0; yy < dy; ++yy) {
                            int newY = 0;
                            if (b == 1 && yy == bit(ymax, pos)) {
                                newY = 1;
                            }
                            int kk = (xx ^ yy);
                            if (c == 1 && kk > bit(k, pos)) {
                                continue;
                            }
                            int newK = 0;
                            if (c == 1 && kk == bit(k, pos)) {
                                newK = 1;
                            }

                            ll dcnt = cnt[a][b][c][r - 1];
                            add(cnt[newX][newY][newK][r], dcnt);
                            ll val = dcnt;
                            mul(val, degs[pos]);
                            if (kk) {
                                add(sum[newX][newY][newK][r], val);
                            }
                            add(sum[newX][newY][newK][r], sum[a][b][c][r - 1]);
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            for (int c = 0; c < 2; ++c) {
                //cout << a << " " << b << " " << c << " " << sum[a][b][c][rmax - 1] << "\n";
                add(ans, sum[a][b][c][rmax - 1]);
                add(ans, cnt[a][b][c][rmax - 1]);
            }
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    degs[0] = 1;
    for (int i = 1; i < 50; ++i) {
        degs[i] = degs[i - 1];
        mul(degs[i], 2);
    }

    int tt;
    cin >> tt;

    while (tt--) {
        ll x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        --x1, --y1, --x2, --y2;
        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        --k;
        ll ans = solve(x2, y2, k);
        if (x1) {
            sub(ans, solve(x1 - 1, y2, k));
        }
        if (y1) {
            sub(ans, solve(x2, y1 - 1, k));
        }
        if (x1 && y1) {
            add(ans, solve(x1 - 1, y1 - 1, k));
        }
        cout << ans << "\n";
    }

}