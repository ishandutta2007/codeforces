#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

set<string> resps={"no", "great!", "not bad", "cool", "are you serious?", "worse", "no way", "terrible", "go die in a hole", "don't even", "don't think so", "don't touch me!"};

set<string> N{"no", "great!", "not bad", "cool", "don't think so", "don't touch me!"};
set<string> G{"no", "are you serious?", "worse", "no way", "terrible", "go die in a hole", "don't even"};

#define assert(x) if ((x)) {} else do{}while(true)
// #define assert(x) if ((x)) {} else { sleep(0.5); cout << "grumpy\n"; exit(0); }

void prettyfy(set<string>& t) {
    for (string s: set<string>(t)) {
        string q;
        for (char c: s) if (isalpha(c) || isspace(c)) q += c;
        t.insert(q);
    }
}

int main() {
#ifdef LOCAL
    // freopen("b.in", "r", stdin);
#endif

    prettyfy(resps);
    prettyfy(N);
    prettyfy(G);

    int cnt = 0;
    int i = 0;
    for (i = 0; i < 10; ++i) {
        cout << i << endl;
        string s;
        getline(cin, s);
        for (char &c: s) c = tolower(c);
        // assert(resps.count(s));
        if (s == "no") ++cnt;
        if (!G.count(s) || cnt > 3) { cout << "normal\n"; break; }
        if (!N.count(s)) { cout << "grumpy\n"; break; }
    }
    while (i < 10) cout << i++ << endl;
    // while (true) {}

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}