#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int A, B, Q;
        cin >> A >> B >> Q;
        vector<int> v(A * B), w(A * B + 1);
        REP(i, A * B) v[i] = (i % A % B != i % B % A);
        REP(i, A * B) w[i + 1] = w[i] + v[i];
        while (Q--)
        {
            lint l, r;
            cin >> l >> r;
            lint ret = 0;
            int i = l % (A * B);
            while (l <= r and i < A * B)
            {
                ret += v[i];
                l++, i++;
            }
            i = r % (A * B);
            while (l <= r and i >= 0)
            {
                ret += v[i];
                r--, i--;
            }
            if (l < r)
            {
                ret += (r - l + 1) / (A * B) * w.back();
            }
            cout << ret << ' ';
        }
        cout << '\n';
    }
}