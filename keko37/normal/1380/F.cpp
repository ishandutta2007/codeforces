#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;
const int MOD = 998244353;

int n, m, ofs = 1, d;
string s;
int t[MAXN * 4][2][2], lef[MAXN * 4], rig[MAXN * 4];

inline int get (int x) {
    return min(x + 1, 19 - x);
}

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void mrg (int x) {
    int mid = (lef[x] + rig[x]) / 2;
    int val = (s[mid] - '0') * 10 + (s[mid + 1] - '0');
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            t[x][a][b] = mul(t[2 * x][a][0], t[2 * x + 1][0][b]);
            if (10 <= val  && val <= 18) {
                t[x][a][b] = add(t[x][a][b], mul(mul(t[2 * x][a][1], t[2 * x + 1][1][b]), get(val)));
            }
        }
    }
}

string nula (int x) {
    string res = "";
    for (int i = 0; i < x; i++) res += '0';
    return res;
}

void tour_init () {
    while (ofs < n) ofs *= 2;
    for (int i = 0; i < ofs; i++) {
        lef[i + ofs] = rig[i + ofs] = i;
        t[i + ofs][0][0] = t[i + ofs][0][1] = t[i + ofs][1][0] = 1;
    }
    s = nula(ofs - n) + s;
    d = ofs - n;
    for (int i = 0; i < n; i++) {
        t[i + d + ofs][0][0] = get(s[i + d] - '0');
    }
    for (int i = ofs - 1; i > 0; i--) {
        lef[i] = lef[2 * i];
        rig[i] = rig[2 * i + 1];
        mrg(i);
    }
}

void update (int pos, int val) {
    pos += d + ofs;
    t[pos][0][0] = get(val);
    pos /= 2;
    while (pos > 0) {
        mrg(pos);
        pos /= 2;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    tour_init();
    for (int i = 0; i < m; i++) {
        int pos, val;
        cin >> pos >> val;
        s[pos - 1 + d] = (char) ('0' + val);
        update(pos - 1, val);
        cout << t[1][0][0] << '\n';
    }
    return 0;
}