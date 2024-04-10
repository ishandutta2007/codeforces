#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int n;
char res[MAXN];
multiset <char> st[MAXN][MAXN];

void ispis (string s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            for (int k = i; k <= j; k++) {
                cout << s[k];
            }
            cout << endl;
        }
    }
}

void pitaj (int a, int b) {
    cout << "? " << a << " " << b << endl;
    int len = b - a + 1;
    int tc = len * (len + 1) / 2;

    int cnt[26][MAXN], t[26][MAXN];
    memset(cnt, 0, sizeof cnt);
    memset(t, 0, sizeof t);
    for (int i = 0; i < tc; i++) {
        string s;
        cin >> s;
        if (a == b) {
            res[n] = s[0];
            return;
        }
        int br = s.size();
        for (auto c : s) cnt[c - 'a'][br]++;
    }

    for (int c = 0; c < 26; c++) {
        t[c][1] = cnt[c][1];
        for (int i = 2; i * 2 <= len + 1; i++) {
            t[c][i] = cnt[c][i] - cnt[c][i - 1];
        }
        for (int i = 1; i * 2 <= len + 1; i++) {
            int val = t[c][i] - t[c][i + 1];
            for (int w = 0; w < val; w++) {
                st[a + i - 1][b - i + 1].insert(c + 'a');
            }
        }
    }
}

inline void brisi (int lo, int hi, char c) {
    if (lo == 0 || lo > n || hi == 0 || hi > n) return;
    if (st[lo][hi].find(c) != st[lo][hi].end()) st[lo][hi].erase(st[lo][hi].find(c));
}

int main () {
    cin >> n;
    if (n == 1) {
        cout << "? 1 1" << endl;
        string s; cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    if (n == 2) {
        cout << "? 1 1" << endl;
        string s; cin >> s;
        cout << "? 2 2" << endl;
        string t; cin >> t;
        cout << "! " << s + t << endl;
        return 0;
    }
    pitaj(n, n);
    pitaj(1, n);
    pitaj(1, n - 1);
    int lo = 1, hi = n, tip = 0;
    st[lo][hi].erase(st[lo][hi].find(res[n]));
    for (int i = 0; i < n-1; i++) {
        if (tip == 0) {
            res[lo] = *st[lo][hi].begin();
            brisi(lo, hi, res[lo]);
            brisi(lo, hi - 1, res[lo]);
            hi--;
        } else {
            res[hi] = *st[lo][hi].begin();
            brisi(lo, hi, res[hi]);
            brisi(lo + 1, hi, res[hi]);
            lo++;
        }
        tip = !tip;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << res[i];
    cout << endl;
    return 0;
}