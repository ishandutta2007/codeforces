#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<int> c(200001);
    for (auto x : A) c[x]++;
    int n = 0;
    REP(i, 200001) if (c[i] > c[n]) n = i;
    printf("%d\n", N - c[n]);
    int j = 0;
    while (A[j] != n) j++;
    IREP(i, j)
    {
        if (A[i] < n)
        {
            printf("1 %d %d\n", i + 1, i + 2);
        }
        if (A[i] > n)
        {
            printf("2 %d %d\n", i + 1, i + 2);
        }
    }
    FOR(i, j + 1, N)
    {
        if (A[i] < n)
        {
            printf("1 %d %d\n", i + 1, i);
        }
        if (A[i] > n)
        {
            printf("2 %d %d\n", i + 1, i);
        }
    }            
}