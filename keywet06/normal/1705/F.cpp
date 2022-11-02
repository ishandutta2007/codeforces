#include <bits/stdc++.h>

const int N = 1005;

char s[N], t[N], Ans[N];

int n, ct1, ct2;

inline void flip(char& ch) { ch = "FT"[ch == 'F']; }

inline int ask(char* s) {
    for (int i = 1; i <= n; ++i) std::cout << s[i];
    std::cout << std::endl;
    int x;
    std::cin >> x;
    if (x == n) exit(0);
    return x;
}

int main() {
    int i;
    for (std::cin >> n, i = 1; i <= n; ++i) s[i] = t[i] = 'T';
    ct1 = ask(s);
    for (i = 2; i <= n; i += 2) t[i] = 'F';
    ct2 = ask(t);
    for (i = 1; i <= n; ++i) s[i] = 'T';
    int m = n / 3;
    for (i = 1; i <= 2 * m; i += 2) {
        flip(s[i]), flip(s[i + 1]);
        int ct = ask(s), id = 2 * m + (i + 1) / 2;
        if (ct == ct1 + 2) {
            Ans[i] = s[i], Ans[i + 1] = s[i + 1];
            flip(s[i]), flip(s[i + 1]), flip(s[id]), ct = ask(s);
            if (ct == ct1 + 1) {
                Ans[id] = s[id], flip(s[id]);
            } else {
                flip(s[id]), Ans[id] = s[id];
            }
        } else if (ct == ct1 - 2) {
            flip(s[i]), flip(s[i + 1]);
            Ans[i] = s[i], Ans[i + 1] = s[i + 1], flip(s[id]), ct = ask(s);
            if (ct == ct1 + 1) {
                Ans[id] = s[id], flip(s[id]);
            } else {
                flip(s[id]), Ans[id] = s[id];
            }
        } else {
            flip(t[i]), flip(t[i + 1]), flip(t[id]), ct = ask(t);
            if (ct == ct2 + 3) {
                Ans[i] = t[i], Ans[i + 1] = t[i + 1], Ans[id] = t[id];
                flip(t[i]), flip(t[i + 1]), flip(t[id]);
            } else if (ct == ct2 - 3) {
                flip(t[i]), flip(t[i + 1]), flip(t[id]);
                Ans[i] = t[i], Ans[i + 1] = t[i + 1], Ans[id] = t[id];
            } else if (ct == ct2 + 1) {
                Ans[i] = t[i], Ans[i + 1] = t[i + 1];
                flip(t[i]), flip(t[i + 1]), flip(t[id]), Ans[id] = t[id];
            } else {
                flip(t[i]), flip(t[i + 1]), Ans[i] = t[i];
                Ans[i + 1] = t[i + 1], Ans[id] = t[id], flip(t[id]);
            }
        }
    }
    for (i = 3 * m + 1; i <= n; ++i) {
        flip(s[i]);
        int ct = ask(s);
        if (ct == ct1 + 1) {
            Ans[i] = s[i], flip(s[i]);
        } else {
            flip(s[i]), Ans[i] = s[i];
        }
    }
    return ask(Ans), 0;
}