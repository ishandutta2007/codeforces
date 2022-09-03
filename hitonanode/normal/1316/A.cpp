#include <bits/stdc++.h>
using namespace std;
using lint = long long int;


int solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    int T = accumulate(A.begin(), A.end(), 0);
    return min(T, M);
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}