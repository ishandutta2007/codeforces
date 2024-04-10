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

string S, ret;

int main()
{
    cin >> S;
    int N = S.length();
    int i = 0, j = N - 1;
    while (j > i + 1)
    {
        if (S[i] == S[j])
        {
            ret += S[i];
            i++, j--;
        }
        else if (S[i] == S[j - 1])
        {
            ret += S[i];
            i++, j -= 2;
        }
        else if (S[i + 1] == S[j])
        {
            ret += S[i + 1];
            i += 2, j--;
        }
        else if (S[i + 1] == S[j - 1])
        {
            if (i + 1 == j - 1) break;
            ret += S[i + 1];
            i += 2, j -= 2;
        }
    }
    string ret2 = ret;
    reverse(ALL(ret2));
    if (i <= j)
    {
        cout << ret + S[i] + ret2 << endl;
    }
    else
    {
        cout << ret + ret2 << endl;
    }
}