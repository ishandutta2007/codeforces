#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int dot(pint v, pint u)
{
    return v.first * u.first + v.second * u.second;
}
int cross(pint v, pint u)
{
    return v.first * u.second - v.second * u.first;
}

int norm2(pint p)
{
    return dot(p, p);
}

double norm(pint p)
{
    return sqrt(norm2(p));
}

constexpr double INF = 1e30;
int main()
{
    int N;
    cin >> N;
    vector<pint> X(N), V(N);
    vector<double> S(N);
    vector<double> normV(N);
    REP(i, N) cin >> X[i].first >> X[i].second >> V[i].first >> V[i].second >> S[i];

    REP(i, N)
    {
        int g = abs(gcd(V[i].first, V[i].second));
        V[i].first /= g, V[i].second /= g;
        normV[i] = norm(V[i]);
    }

    double ret = INF;

    REP(i, N) REP(j, i)
    {
        int c = cross(V[i], V[j]);
        if (c == 0)
        {
            pint dx = X[j] - X[i];
            double speed = 0;
            if (cross(dx, V[i])) continue;
            if (dot(dx, V[i]) > 0) speed += S[i];
            if (dot(dx, V[j]) < 0) speed += S[j];
            if (speed) chmin(ret, norm(dx) / speed);
        }
        else
        {
            double ti = 1.0 * cross(V[j], X[j] - X[i]) * normV[i] / -c;
            double tj = 1.0 * cross(V[i], X[i] - X[j]) * normV[j] / c;
            if (ti >= 0 and tj >= 0)
            {
                chmin(ret, max(ti / S[i], tj / S[j]));
            }
        }
    }
    if (ret == INF) puts("No show :(");
    else cout << ret << '\n';
}