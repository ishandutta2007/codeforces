#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)



int main()
{
    int N, K;
    cin >> N >> K;
    string A;
    cin >> A;

    string ret = A;
    REP(i, ret.length()) ret[i] = A[i % K];

    if (ret < A)
    {
        bool carry = true;
        int k = K - 1;
        while (carry) {
            carry = (ret[k] == '9');
            if (carry) ret[k] = '0';
            else ret[k]++;
            k--;
        }
        REP(i, ret.length()) ret[i] = ret[i % K];
    }
    cout << ret.length() << endl;
    cout << ret << endl;
}