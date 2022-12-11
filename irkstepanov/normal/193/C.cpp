#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

bool exist = true;
string A = "", B = "", C = "";

void f(int a, int b, int c)
{
    if ((a + b + c) % 2) {
        exist = false;
        return;
    }
    if (max(max(a, b), c) > a + b + c - max(max(a, b), c)) {
        exist = false;
        return;
    }
    while (a || b || c) {
        if (a == max(max(a, b), c)) {
            if (b) {
                A += "a", B += "b", C += "b";
                --b;
            } else if (c) {
                A += "b", B += "a", C += "b";
                --c;
            }
            --a;
            continue;
        }
        if (b == max(max(a, b), c)) {
            if (a) {
                A += "a", B += "b", C += "b";
                --a;
            } else if (c) {
                A += "b", B += "b", C += "a";
                --c;
            }
            --b;
            continue;
        }
        if (c == max(max(a, b), c)) {
            if (a) {
                A += "b", B += "a", C += "b";
                --a;
            } else if (b) {
                A += "b", B += "b", C += "a";
                --b;
            }
            --c;
            continue;
        }
    }
}

int main()
{

    int h12, h13, h14, h23, h24, h34;
    cin >> h12 >> h13 >> h14 >> h23 >> h24 >> h34;

    f(h12, h13, h23);
    if (!exist) {
        cout << "-1\n";
        return 0;
    }

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < sz(A); ++i) {
        if (A[i] != B[i] && A[i] != C[i]) {
            ++a;
        } else if (B[i] != A[i] && B[i] != C[i]) {
            ++b;
        } else {
            ++c;
        }
    }

    int x = h14, y = h24, z = h34;
    int u = x - a;
    int v = y - b;
    int t = z - c;
    if (abs(u) % 2 != abs(v) % 2 || abs(u) % 2 != abs(t) % 2) {
        cout << "-1\n";
        return 0;
    }

    int kappa = (u - v) / 2;
    int ksi = (u - t) / 2;

    int lower = max(-kappa, 0);
    int upper = min(b - kappa, a);
    if (lower > upper) {
        cout << "-1\n";
        return 0;
    }

    lower = max(lower, -ksi);
    upper = min(upper, c - ksi);
    upper = min(upper, (v + t) / 2);
    if (lower > upper) {
        cout << "-1\n";
        return 0;
    }

    int alpha = upper;
    int betta = kappa + alpha;
    int gamma = ksi + alpha;

    string D = "";

    for (int i = 0; i < sz(A); ++i) {
        if (A[i] != B[i] && A[i] != C[i]) {
            if (alpha) {
                D += A[i];
                --alpha;
            } else {
                D += B[i];
            }
        } else if (B[i] != A[i] && B[i] != C[i]) {
            if (betta) {
                D += B[i];
                --betta;
            } else {
                D += C[i];
            }
        } else {
            if (gamma) {
                D += C[i];
                --gamma;
            } else {
                D += A[i];
            }
        }
    }

    int cnt = x;
    for (int i = 0; i < sz(A); ++i) {
        if (A[i] != D[i]) {
            --cnt;
        }
    }

    while (cnt--) {
        A += "a", B += "a", C += "a";
        D += "b";
    }

    cout << sz(A) << "\n";
    cout << A << "\n" << B << "\n" << C << "\n" << D << "\n";

}