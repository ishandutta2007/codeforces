#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    cin >> A;

    auto z = srtunq(A);
    int lo = -1, hi = z.size() - 1;
    while (hi - lo > 1)
    {
        int c = (lo + hi) / 2;

        int l0 = 0, l1 = 1;
        for (auto x : A)
        {
            if (l0 % 2 or x <= z[c]) l0++;
            if (l1 % 2 or x <= z[c]) l1++;
        }
        l1--;
        if (l0 >= K or l1 >= K) hi = c;
        else lo = c;
    }
    cout << z[hi] << '\n';
}