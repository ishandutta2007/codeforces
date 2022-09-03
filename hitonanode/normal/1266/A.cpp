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



int main()
{
    int N;
    cin >> N;
    while (N--) {
        string S;
        cin >> S;
        sort(ALL(S));
        lint val = 0;
        int g = 0;
        int z = 0;
        for (auto c : S)
        {
            val += c - '0';
            if ((c - '0') % 2 == 0) g++;
            if (c == '0') z++;
        }
        if (val % 3 == 0 and g > 1 and z) puts("red");
        else puts("cyan");
    }
}