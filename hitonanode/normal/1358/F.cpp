#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void impossible()
{
    puts("IMPOSSIBLE");
    exit(0);
}

vector<lint> A, Arev;
void bcheck(const vector<lint> &b)
{
    for (auto &x : b) if (x <= 0) impossible();
    REP(i, b.size())
    {
        if (b[i] < min(A[i], Arev[i])) impossible();
    }
    REP(i, b.size() - 1)
    {
        if (b[i] > b[i + 1]) impossible();
    }
}

void answer(string s)
{
    int pcnt = 0;
    for (auto c : s) pcnt += (c == 'P');
    if (pcnt > 200000)
    {
        cout << "BIG\n" << pcnt << '\n';
    }
    else
    {
        cout << "SMALL\n" << s.length() << '\n' << s << '\n';
    }
    exit(0);
}
int main()
{
    int N;
    cin >> N;
    vector<lint> B(N);
    A.resize(N);
    cin >> A >> B;
    Arev = A;
    reverse(Arev.begin(), Arev.end());
    if (A == B)
    {
        puts("SMALL");
        puts("0");
        puts("");
        return 0;
    }
    if (Arev == B)
    {
        puts("SMALL");
        puts("1");
        puts("R");
        return 0;
    }

    if (N == 1) impossible();

    string retb;
    if (B[0] > B.back())
    {
        retb += ('R');
        reverse(B.begin(), B.end());
    }
    bcheck(B);

    REP(t, 3000000)
    {
        retb += ('P');
        IREP(i, N - 1) B[i + 1] -= B[i];
        if (A == B)
        {
            reverse(retb.begin(), retb.end());
            answer(retb);
        }
        if (Arev == B)
        {
            retb += ('R');
            reverse(retb.begin(), retb.end());
            answer(retb);
        }

        if (B[0] > B.back())
        {
            retb += ('R');
            reverse(B.begin(), B.end());
        }
        bcheck(B);
    }

    lint cnt = 0;
    for (auto c : retb) cnt += (c == 'P');
    sort(A.begin(), A.end());

    if (N == 2)
    {
        while (true)
        {
            sort(B.begin(), B.end());
            if (A == B)
            {
                cout << "BIG\n" << cnt << '\n';
                return 0;
            }
            if (A[0] > B[0] or A[1] > B[1]) impossible();
            lint diff = -1;
            if (A[0] == B[0]) diff = B[1] - A[1];
            else diff = B[1] - B[0];
            lint step = (diff + B[0] - 1) / B[0];
            step = max(step, 1LL);
            cnt += step;
            B[1] -= B[0] * step;
            continue;
        }
    }

    exit(8);
}