#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// END /////
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;
    vector<pbds_set<int>> cH(N), cW(M);
    REP(i, N) REP(j, M) cH[i].insert(A[i][j]), cW[j].insert(A[i][j]);

    REP(i, N)
    {
        REP(j, M)
        {
            int lower = max(cH[i].order_of_key(A[i][j]), cW[j].order_of_key(A[i][j]));
            int upper = max(cH[i].size() - cH[i].order_of_key(A[i][j] + 1), cW[j].size() - cW[j].order_of_key(A[i][j] + 1));
            printf("%d ", lower + upper + 1);
        }
        puts("");
    }
}