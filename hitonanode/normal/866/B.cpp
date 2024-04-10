#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<lint> sol(vector<plint> v, lint S)
{
    sort(v.rbegin(), v.rend());
    vector<lint> ret;
    lint rem = S;
    lint val = 0;
    for (auto p : v)
    {
        lint g = p.first, i = p.second;
        while (i)
        {
            lint use = min(i, rem);
            i -= use;
            rem -= use;
            val += g * use;
            if (!rem)
            {
                rem = S;
                ret.emplace_back(val);
                val = 0;
            }
        }
    }
    if (val) ret.emplace_back(val);
    return ret;
}

int main()
{
    lint N, S;
    cin >> N >> S;
    vector<plint> va, vb;

    lint stot = 0;
    lint ret = 0;
    REP(i, N)
    {
        lint s, a, b;
        cin >> s >> a >> b;
        lint m = min(a, b);
        ret += s * m;
        a -= m, b -= m;

        lint no = max(0LL, s / S - 1);
        ret += no * S * max(a, b);
        s -= no * S;
        stot += s;
        if (a) va.emplace_back(a, s);
        if (b) vb.emplace_back(b, s);
    }

    lint np = (stot + S - 1) / S;

    vector<lint> wa = sol(va, S), wb = sol(vb, S);
    // dbg(wa);
    // dbg(wb);
    wa.insert(wa.end(), ALL(wb));
    sort(wa.rbegin(), wa.rend());
    REP(i, min<int>(wa.size(), np))
    {
        ret += wa[i];
    }
    cout << ret << '\n';
}