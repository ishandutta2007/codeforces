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
typedef pair<ll, int> pll;

int cnt[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
    int d, m, y;
    bool valid()
    {
        if (m > 12) {
            return false;
        }
        if (m == 2) {
            if (y % 4 == 0) {
                return d <= 29;
            } else {
                return d <= 28;
            }
        } else {
            return d <= cnt[m - 1];
        }
    }
    bool operator<=(const date& other) const
    {
        if (y != other.y) {
            return y < other.y;
        }
        if (m != other.m) {
            return m < other.m;
        }
        return d <= other.d;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string a, b;
    cin >> a >> b;

    date final;
    final.d = (a[0] - '0') * 10 + (a[1] - '0');
    final.m = (a[3] - '0') * 10 + (a[4] - '0');
    final.y = (a[6] - '0') * 10 + (a[7] - '0');

    int x = (b[0] - '0') * 10 + (b[1] - '0');
    int y = (b[3] - '0') * 10 + (b[4] - '0');
    int z = (b[6] - '0') * 10 + (b[7] - '0');

    vector<int> v = {x, y, z};

    do {
        date d;
        d.d = v[0], d.m = v[1], d.y = v[2];
        if (!d.valid()) {
            continue;
        }
        date r = d;
        r.y += 18;
        if (r.d == 29 && d.m == 2) {
            r.d = 1;
            r.m = 3;
        }
        if (r <= final) {
            //cout << r.d << " " << r.m << " " << r.y << " " << final.d << " " << final.m << " " << final.y << "\n";
            cout << "YES\n";
            return 0;
        }
    } while (next_permutation(all(v)));

    cout << "NO\n";

}