const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

#define double long double

vector<double> add_sand(int n, vector<double> c, vector<double> p, int k, vector<double> &points)
{
    vector<double> res = c;

    double total_added = 0;
    points.push_back(0.0);

    for (int i = 1; i <= k; i++)
    {
        vector<pair<double, int> > ratios(n);
        for (int j = 0; j < n; j++)
            ratios[j] = {res[j] / p[j], j};
        sort(ratios.begin(), ratios.end());
        double x = ratios[i].first;
        double alpha = 1;

        double can_add_before_flip = 1e12;
        double want_add = 0;
        for (int j = 0; j < i; j++)
        {
            int jj = ratios[j].second;
            want_add += alpha * (p[jj] * x - res[jj]);
        }
        double sum = accumulate(all(res), (double)0.0);
        double P = accumulate(all(p), (double)0.0);
        for (int j = i; j < n; j++)
        {
            int jj = ratios[j].second;
            if (res[jj] / sum - p[jj] / P > 1e-8)
            {
                can_add_before_flip = min(can_add_before_flip, res[jj] * P / p[jj] - sum);
            }
        }
        for (int j = 0; j < i; j++)
        {
            int jj = ratios[j].second;
            if (res[jj] / sum - p[jj] / P < - 1e-8)
            {
                double want_add_here = (p[jj] * x - res[jj]);
                double perc = want_add_here / want_add;
                double ff = (p[jj] * sum - P * res[jj]) / (P * perc - p[jj]);
                can_add_before_flip = min(can_add_before_flip, ff);
            }
        }

        int fl = 0;
        if (want_add > can_add_before_flip)
        {
            alpha = can_add_before_flip / want_add, fl = 1;
        }

        for (int j = 0; j < i; j++)
        {
            int jj = ratios[j].second;
            double y = alpha * (p[jj] * x - res[jj]);
            res[jj] += y;
            total_added += y;
        }
        points.push_back(total_added);
        i -= fl;
    }
    return res;
}

vector<double> add_sand(int n, vector<double> c, vector<double> p, double L)
{
    int ans = 0;
    vector<double> res = c;

    for (int i = 1; i < n; i++)
    {
        vector<pair<double, int> > ratios(n);
        for (int j = 0; j < n; j++)
            ratios[j] = {res[j] / p[j], j};
        sort(ratios.begin(), ratios.end());
        double x = ratios[i].first;
        double alpha = 0;
        for (int j = 0; j < i; j++)
        {
            int jj = ratios[j].second;
            alpha += (p[jj] * x - res[jj]);
        }
        if (L > alpha) alpha = 1;
        else alpha = L / alpha;
        for (int j = 0; j < i; j++)
        {
            int jj = ratios[j].second;
            double y = alpha * (p[jj] * x - res[jj]);
            L -= y;
            res[jj] += y;
        }
    }
    return res;
}

void solve()
{
    cout << setprecision(20);

    auto comp = [&](vector<double> a, vector<double> b){
        double res = 0;
        double A = accumulate(all(a), (double)0.0);
        double B = accumulate(all(b), (double)0.0);
        for (int i = 0; i < a.size(); i++)
        {
            res += abs(a[i] / A - b[i] / B);
        }
        return res;
    };

    struct piece{
        double Const;
        double a, b, c, d;
        double L, R;
    };

    int t, q;
    cin >> t >> q;
    vector<vector<piece> > func(t);
    vector<double> lst(t);
    double W = 0;
    for (int ii = 0; ii < t; ii++)
    {
        int ni;
        cin >> ni;
        vector<double> c(ni), p(ni);
        for (int i = 0; i < ni; i++)
        {
            int r;
            cin >> r;
            c[i] = r;
        }
        for (int i = 0; i < ni; i++)
        {
            int r;
            cin >> r;
            p[i] = r;
        }
        double P = accumulate(all(p), (double)0.0);

        vector<double> points2;
        add_sand(ni, c, p, ni - 1, points2);

        for (int i = 0; i + 1 < points2.size(); i++)
        {
            double D = (points2[i] + points2[i + 1]) / 2;
            vector<double> cur = add_sand(ni, c, p, D);
            double C = 0;
            double alpha = 0;
            for (int j = 0; j < ni; j++)
            {
                if (cur[j] / accumulate(all(cur), (double)0.0) - p[j] / P < -1e-8)
                {
                    C += p[j] / P;
                    alpha -= c[j];
                }
                else
                {
                    C -= p[j] / P;
                    alpha += c[j];
                }
            }

            double lpart = (comp(cur, p) - C) * (accumulate(all(c), (double)0.0) + D) - alpha;
            double betta = lpart / D;

            piece f = {C, alpha, betta, accumulate(all(c), (double)0.0), 1, points2[i], points2[i + 1]};

            f.Const += f.b;
            f.a -= f.c * f.b;
            if (f.a < 0)
                f.a = 1e-9;
            f.a = sqrt(f.a);
            f.b = 0;
            func[ii].push_back(f);
        }
    }

    vector<pair<double, int> > asks(q);
    vector<double> answers(q);
    int pntq = 0;

    for (int i = 0; i < q; i++)
    {
        long long r;
        cin >> r;
        asks[i].first = r;
        asks[i].second = i;
    }
    sort(all(asks));

    vector<int> pnt(t, -1);
    vector<pair<double, int> > changes;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < func[i].size(); j++)
        {
            changes.push_back({ - func[i][j].a * func[i][j].a / (func[i][j].L + func[i][j].c) / (func[i][j].L + func[i][j].c), i + 1});
            changes.push_back({ - func[i][j].a * func[i][j].a / (func[i][j].R - 1e-12 + func[i][j].c) / (func[i][j].R - 1e-12 + func[i][j].c), - i - 1});
        }
    }
    sort(all(changes));

    double sum_of_a = 0;
    double cur_x = 0, cur_y = 0;
    for (int i = 0; i < t; i++)
        cur_y += func[i][0].Const + (func[i][0].a * func[i][0].a) / (func[i][0].c);

    int cnt_func = 0;

    for (int i = 0; i + 1 < changes.size(); i++)
    {
        if (changes[i].second < 0)
        {
            cnt_func--;
            int id = -changes[i].second - 1;
            sum_of_a -= func[id][pnt[id]].a;
        }
        else
        {
            cnt_func++;
            int id = changes[i].second - 1;
            pnt[id]++;
            sum_of_a += func[id][pnt[id]].a;
        }
        if (cnt_func <= 0)
        {
            continue;
        }

        // (a^2 / x)' = changes[i].first
        // -a^2 / x^2 = changes[i].first
        double x_local = sqrt(- sum_of_a * sum_of_a / changes[i].first);
        double move_x = x_local - cur_x;
        double move_y = cur_y - (sum_of_a * sum_of_a / x_local);
        double later_a = 0;

        double derivative_at_the_end = changes[i + 1].first;
        double len = sqrt(- sum_of_a * sum_of_a / derivative_at_the_end) - x_local;
        while (pntq < q && asks[pntq].first <= cur_x + len)
        {
            answers[asks[pntq].second] = sum_of_a * sum_of_a / (asks[pntq].first + move_x) + move_y;
            pntq++;
        }
        cur_x += len;
        cur_y = sum_of_a * sum_of_a / (cur_x + move_x) + move_y;
    }

    for (int i = 0; i < q; i++)
    {
        if (answers[i] < 1e-7)
            cout << 0 << "\n";
        else
            cout << answers[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}