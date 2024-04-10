#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


array<int, 8001> arr;
int solve()
{
    fill(arr.begin(), arr.end(), 0);
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    for (int i = 0; i < N; i++)
    {
        int acc = A[i];
        for (int j = i + 1; j < N; j++)
        {
            acc += A[j];
            if (acc > 8000) break;
            arr[acc]++;
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++) ret += (arr[A[i]] > 0);
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}