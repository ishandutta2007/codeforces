#include <bits/stdc++.h>
 
using namespace std;
#define files1 freopen("input.txt", "r", stdin)
#define pb push_back
const int maxn = 5e3 + 10;
 
bool is_c[maxn];
bool what_bit[maxn][maxn];
 
int l[maxn], r[maxn];
int oper[maxn];
 
int res[maxn];
 
int n;
 
int solve(int a, int b, int op) {
    if (op == 0) return a | b;
    if (op == 1) return a & b;
    if (op == 2) return a ^ b;
}
 
int calc(int pos, int x) {
    res[0] = x;
    int ans = 0;
 
    for (int i = 1; i <= n; i++) {
        if (is_c[i]) {
            res[i] = what_bit[i][pos];
        } else {
            res[i] = solve(res[l[i]], res[r[i]], oper[i]);
        }
        ans += res[i];
    }
 
    return ans;
}
 
int main() {
    int m;
    // files1;
    ios_base::sync_with_stdio(0);
 
    cin >> n >> m;
 
    map<string, int> sot;
    int sz = 1;
 
    vector<string> tokens;
    for (int i = 0; i < n; i++) {
        string s;
        if (i == 0) 
        getline(cin, s);
        getline(cin, s);
        string tmp;
        tokens.clear();
    //  cout << s << endl;
    // return 0;
        s += ' ';
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == ' ') {
                tokens.pb(tmp);
                tmp.clear();
            } else tmp += s[j];
        }
 
        if (tokens.size() == 3) {
            is_c[i + 1] = 1;
            s = tokens.back();
            for (int j = 0; j < m; j++)
                what_bit[i + 1][j] = s[j] - '0';
        } else {
            s = tokens[2], tmp = tokens[4];
            string op = tokens[3];
 
            int a, b;
            int x;
 
            if (op == "OR") x = 0;
            if (op == "AND") x = 1;
            if (op == "XOR") x = 2;
 
            if (s == "?") a = 0;
            else {
                a = sot[s];
            }
 
            if (tmp == "?") b = 0;
            else {
                b = sot[tmp];
            }
 
            l[i + 1] = a, r[i + 1] = b;
            oper[i + 1] = x;
        }
        sot[tokens[0]] = sz++;
 
        // cout << is_c[i + 1] << endl;
    }
    string mn, mx;
 
    for (int i = 0; i < m; i++) {
        int f = calc(i, 0);
        int s = calc(i, 1);
 
        if (f == s) {
            mn += '0';
            mx += '0';
        } else {
            if (f > s)
                mx += '0', mn += '1';
            else
                mn += '0', mx += '1';
        }
    }
    cout << mn << endl << mx << endl;
    return 0;
}