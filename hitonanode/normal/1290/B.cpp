#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
 
 
int main()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<vector<int>> nxt(26, vector<int>(N + 1, N + 10));
    IREP(i, N) {
        REP(d, 26) nxt[d][i] = nxt[d][i + 1];
        nxt[S[i] - 'a'][i] = i;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        if (L == R) {
            puts("Yes");
        }
        else {
            L--;
            int cnt = 0;
            REP(d, 26) if (nxt[d][L] < R) cnt++;
            if (cnt == 1) puts("No");
            else if (cnt > 2 or S[L] != S[R - 1]) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }
}