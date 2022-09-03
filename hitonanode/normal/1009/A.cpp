#include <bits/stdc++.h>
using namespace std;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> C(N), A(M);
    cin >> C >> A;
    A.push_back(0);
    int j = 0, ret = 0;
    for (auto x : C) if (x <= A[j]) j++, ret++;
    cout << ret << "\n";
}