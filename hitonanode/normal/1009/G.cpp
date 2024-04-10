#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<int> ok(N, 63);
    int M;
    cin >> M;
    while (M--) {
        int b;
        string s;
        cin >> b >> s;
        ok[b - 1] = 0;
        for (auto c : s) ok[b - 1] += 1 << (c - 'a');
    }
    vector<int> fr(6);
    for (auto c : S) fr[c - 'a']++;
    vector<int> scnt(64);
    for (auto c : ok) scnt[c]++;
    string ret;

    REP(i, N) {
        int nxt = -1;
        scnt[ok[i]]--;
        vector<int> scntconv = scnt;
        REP(d, 6) REP(S, 64) if ((S >> d) % 2 == 0) scntconv[S + (1 << d)] += scntconv[S];

        REP(cand, 6) if (((ok[i] >> cand) & 1) and nxt == -1 and fr[cand]) {
            bool f = true;
            fr[cand]--;
            REP(S, 64) {
                int w = 0;
                REP(d, 6) if ((S >> d) & 1) w += fr[d];
                if (w < scntconv[S]) f = false;
            }
            fr[cand]++;
            if (f) nxt = cand;
        }
        if (nxt < 0) {
            puts("Impossible");
            return 0;
        }
        ret += 'a' + nxt;
        fr[nxt]--;
    }
    cout << ret << endl;
}