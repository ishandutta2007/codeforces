#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


vector<int> rep;
vector<string> dict;

int K;
void add(int n, string S)
{
    if (!n) return;
    rep.push_back(n);
    dict.push_back(S);
    K -= n * S.length();
}

int main()
{
    int N, M;
    cin >> N >> M >> K;
    if (4 * N * M - 2 * (N + M) < K) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int h = 0;
    while (K)
    {
        if (h == N - 1) {
            int r = min(K, M - 1);
            add(r, "R");
            int l = min(K, r);
            add(l, "L");
            add(K, "U");
        }
        else {
            int rdu = min(K / 3, M - 1);
            add(rdu, "RDU");
            if (K < 3 and rdu < M - 1) {
                add(K > 0, "R");
                add(K > 0, "D");
            }
            int l = min(K, rdu);
            add(l, "L");
            add(K > 0, "D");
            h++;
        }
    }
    printf("%lu\n", rep.size());
    REP(i, rep.size()) {
        printf("%d %s\n", rep[i], dict[i].c_str());
    }
}