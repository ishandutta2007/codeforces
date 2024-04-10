#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

bool solve()
{
    string S, T, P;
    cin >> S >> T >> P;
    int N = S.length(), M = T.length();
    int j = 0;
    REP(i, N)
    {
        while (j < M and T[j] != S[i]) j++;
        if (j == M) return false;
        j++;
    }
    map<char, int> couPS, couT;
    for (auto c : P) couPS[c]++;
    for (auto c : S) couPS[c]++;
    for (auto c : T) couT[c]++;
    for (auto pa : couT) if (couPS[pa.first] < pa.second) return false;
    return true;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q) if (solve()) puts("YES"); else puts("NO");
}