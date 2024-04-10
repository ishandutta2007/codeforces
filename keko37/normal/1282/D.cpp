#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int n, cnt, naso;
string s;

int pitaj (string t) {
    if (t.size() > 300) return t.size();
    cout << t << endl;
    int res; cin >> res;
    if (res == 0) naso = 1;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n = 1 + pitaj("a");
    if (naso) return 0;
    for (int i = 0; i < n; i++) s += 'a';
    cnt = pitaj(s);
    if (naso) return 0;
    if (cnt == n) {
        s = "";
        for (int i = 0; i < n-1; i++) s+= 'b';
        pitaj(s);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        s[i] = 'b';
        int val = pitaj(s);
        if (val > cnt) s[i] = 'a';
        cnt = min(cnt, val);
        if (cnt == 0) break;
    }
    return 0;
}