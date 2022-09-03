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

std::vector<int> mp_algorithm(std::string s) {
    int N = s.length();
    std::vector<int> ret(N + 1, -1);
    int j = -1;
    for (int i = 0; i < N;  i++) {
        while (j >= 0 and s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}

string ret;
int one, zero;

void add_one()
{
    if (one > 0) one--, ret += "1";
    else zero--, ret += "0";
}
void add_zero()
{
    if (zero > 0) zero--, ret += "0";
    else one--, ret += "1";
}

int main()
{
    string S, T;
    cin >> S >> T;
    int M = T.length();
    vector<int> mp = mp_algorithm(T);
    int r = M - mp[M];
    for (auto c : S) if (c == '1') one++; else zero++;
    REP(i, S.length())
    {
        int s = i;
        if (s > mp[M]) s = (s - mp[M]) % r + mp[M];
        if (T[s] == '1') add_one();
        else add_zero();
    }
    cout << ret << endl;
}