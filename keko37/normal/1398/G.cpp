#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef complex <double> cd;

const int MAXN = 200005;
const int OFS = 200000;
const double PI = acos(-1);

int n, x, y, q;
int A[MAXN], B[MAXN], sol[1000000 + 5];

void fft (vector <cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void upd (int val) {
    for (int i = val; i <= 5e5; i += val) {
        sol[i] = max(sol[i], val * 2);
    }
}

void get_sums () {
    vector <int> a(MAXN * 2), b(MAXN * 2), res;
    for (int i = 0; i <= n; i++) {
        a[A[i]]++;
        b[B[i]]++;
    }
    res = multiply(a, b);
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != 0 && i - 2 * OFS > 0) upd(i - 2 * OFS + y);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(sol, -1, sizeof sol);
    cin >> n >> x >> y;
    for (int i = 0; i <= n; i++) {
        cin >> A[i];
        B[i] = OFS - A[i];
        A[i] += OFS;
    }
    get_sums();
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        x /= 2;
        cout << sol[x] << " ";
    }
    return 0;
}