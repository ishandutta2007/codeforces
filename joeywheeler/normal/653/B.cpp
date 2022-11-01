#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

map<string,string> m;

bool f(string s) {
    if (sz(s) == 1) return s == "a";
    else {
        auto it = m.find(s.substr(0,2));
        if (it != m.end()) {
            return f(it->second + s.substr(2,sz(s)-2));
        }
        return false;
    }
}

int n, q;
int res = 0;

void gen(string s) {
    if (sz(s) == n) res += f(s);
    else {
        char c[2] = " ";
        for (c[0] = 'a'; c[0] <= 'f'; c[0]++) {
            gen(s+c);
        }
    }
}

int main() {
    cin >> n >> q;
    FO(i,0,q) {
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }

    gen("");
    printf("%d\n", res);
}