#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)


int main()
{
    int n;
    string a;
    vector<int> f(10);
    cin >> n >> a;
    FOR(i, 1, 10) cin >> f[i];

    int status = 0;
    for (auto &c : a)
    {
        int v = c - '0';
        if (f[v] > v and status == 0)
        {
            c = (char)(f[v] + '0');
            status = 1;
        }
        else if (f[v] < v and status == 1)
        {
            cout << a << endl;
            return 0;
        }
        else if (status == 1) c = (char)(f[v] + '0');
    }
    cout << a << endl;
}