#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int N;
vector<lint> A;

int main()
{
    cin >> N;
    A.resize(N);
    REP(i, N) cin >> A[i];
    lint MA = *max_element(ALL(A));
    vector<lint> da;
    for (auto a : A) if (a != MA) da.emplace_back(MA - a);
    lint g = da[0];
    for (auto v : da) g = __gcd(g, v);
    lint y = 0;
    for (auto a : A) y += (MA - a) / g;
    cout << y << " " << g << endl;
}