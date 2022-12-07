#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;

bool pali(string &s) {
    int n = SIZE(s);
    REP(i, n/2) if (s[i] != s[n - i - 1]) return false;
    return true;
}

bool try_one(string& s) {
    int n = SIZE(s);
    FOR(i, 1, n - 1) {
        string w;
        FOR(j, i, n - 1) w.PB(s[j]);
        REP(j, i) w.PB(s[j]);
        if (pali(w) && w != s) return true;
    }
    return false;
}

void jebaj() {
    string s;
    cin >> s;

    int n = SIZE(s);
    map<char, int> mapka;
    for (int i = 0; i < n; i++) {
        if (i * 2 != n - 1) mapka[s[i]]++;
    }
    if (SIZE(mapka) <= 1) {
            cout << "Impossible\n";
    return;
    }

    if (try_one(s)) {
        cout << "1\n";
        return;
    }
    else cout << "2\n";
    return;
}
#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}