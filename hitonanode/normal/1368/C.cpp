#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;




int main()
{
    int N;
    cin >> N;
    N++;
    cout << 1 + 7 * N << '\n' << "0 0" << '\n';
    REP(i, N)
    {
        cout << i * 2 + 0 << ' ' << i * 2 + 1 << '\n';
        cout << i * 2 + 0 << ' ' << i * 2 + 2 << '\n';
        cout << i * 2 + 1 << ' ' << i * 2 + 2 << '\n';
        cout << i * 2 + 2 << ' ' << i * 2 + 2 << '\n';
        cout << i * 2 + 2 << ' ' << i * 2 + 1 << '\n';
        cout << i * 2 + 2 << ' ' << i * 2 + 0 << '\n';
        cout << i * 2 + 1 << ' ' << i * 2 + 0 << '\n';
    }
}