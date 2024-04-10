#include <bits/stdc++.h>

using namespace std;

const int P = 32768;
const int N = 109;

char ch;

string t;
string s[N];

int ans, v, num, p, pos;
int f[P + 5];

int ex();

int gt() {
    int ret = 0;
    if (t[pos] == 'n') return ++pos, v;
    if (t[pos] == 'f') return pos += 2, ret = f[ex()], ++pos, ret;
    while (t[pos] >= '0' && t[pos] <= '9') {
        ret = ret * 10 + (t[pos] - '0'), ++pos;
    }
    return ret;
}
int nex() {
    int ret = gt();
    while (t[pos] == '*' || t[pos] == '/') {
        char tp = t[pos];
        ++pos;
        int t1 = gt();
        if (tp == '*') {
            ret = int((1ll * ret * t1) % P);
        } else {
            ret = (ret / t1) % P;
        }
    }
    return ret;
}
int ex() {
    int ret = nex();
    while (t[pos] == '+' || t[pos] == '-') {
        char tp = t[pos];
        ++pos;
        int t1 = nex();
        if (tp == '+') {
            ret = (ret + t1) % P;
        } else {
            ret = (ret + P - t1) % P;
        }
    }
    return ret;
}
bool iex() {
    int p1, p2, tp;
    p1 = ex();
    if (t[pos] == '=') {
        tp = 0, pos += 2;
    } else if (t[pos] == '<') {
        tp = -1, ++pos;
    } else {
        tp = 1, ++pos;
    }
    p2 = ex();
    if (tp == 0) return p1 == p2;
    if (tp == -1) return p1 < p2;
    if (tp == 1) return p1 > p2;
    return 0;
}
int getans() {
    for (int i = 0; i < num; ++i) {
        t = s[i];
        if (t[0] == 'i') {
            pos = 3;
            if (iex()) return pos += 7, ex();
        } else {
            return pos = 6, ex();
        }
    }
    return -1;
}
int main() {
    cin >> ans >> ch;
    while (ch != '{') cin >> ch;
    num = 0;
    while (true) {
        cin >> ch;
        if (ch == '}') break;
        if (ch == ';') {
            ++num;
        } else {
            s[num] += ch;
        }
    }
    int anst = -1;
    for (int i = 0; i < P; ++i) {
        v = i, f[i] = getans();
        if (f[i] == ans) anst = i;
    }
    cout << anst << '\n';
    return 0;
}