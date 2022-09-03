#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    vector<int> cnt(201);
    for (auto a : A) cnt[a]++;
    int ret = 0;
    for (int a = 1; a <= 200; a++)
    {
        vector<int> C = cnt;
        C[a] = 0;
        int l = 0, r = N - 1;
        int cnt_a = 0;
        chmax(ret, *max_element(C.begin(), C.end()));
        while (l < r)
        {
            if (A[l] != a)
            {
                C[A[l]]--;
                l++;
            }
            else if (A[r] != a)
            {
                C[A[r]]--;
                r--;
            }
            else
            {
                cnt_a += 2;
                chmax(ret, cnt_a + *max_element(C.begin(), C.end()));
                l++;
                r--;
            }
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << "\n";
    }
}