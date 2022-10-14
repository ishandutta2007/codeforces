#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 20005;

int n, cnt;
llint t[MAXN], s[MAXN], dt[MAXN], ds[MAXN], sign[MAXN];
llint nck[MAXN], rev[MAXN], sol[MAXN];

void precompute () {
    for (int i = 1; i <= 2 * n; i++) {
        nck[i] = i * (i - 1) / 2;
        rev[nck[i]] = i;
    }
}

void ask (int pos) {
    cout << "+ " << pos << endl;
    cnt++;
    cin >> t[cnt] >> s[cnt];
    dt[cnt] = t[cnt] - t[cnt - 1];
    ds[cnt] = s[cnt] - s[cnt - 1];
}

void init () {
    ask(1); ask(2); ask(3); ask(1);

    llint a = rev[dt[4]] - 1;
    llint b = rev[dt[2]];
    llint c = rev[dt[3]];
    if (c == 1 && ds[2] == 0) c = 0;
    b = ds[4] / (c + 1) - 1;
    sol[1] = a; sol[2] = b; sol[3] = c;

    sign[4] = ds[3] - (a + 1) * (b + 1);
}

void solve (int pos) {
    ask(pos);
    llint val = rev[dt[cnt]];
    if (val == 1 && sign[pos] == 0) val = 0;
    sol[pos] = val;
    sign[pos + 1] = ds[cnt] - (sol[pos - 2] + 1) * (sol[pos - 1] + 1);
}

void last () {
    sol[n] = sign[n] / (sol[n - 2] + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t[0] >> s[0];
    precompute();
    init();
    for (int i = 4; i < n; i++) solve(i);
    last();
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << sol[i] << " "; cout << endl;
    return 0;
}