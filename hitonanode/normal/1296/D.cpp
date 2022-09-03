#include <bits/stdc++.h>
using namespace std;
// using lint = long long int;
using lint = int;

int main()
{
    lint N, A, B, K;
    cin >> N >> A >> B >> K;
    multiset<int> req;
    while (N--) {
        lint H;
        cin >> H;
        H %= (A + B);
        if (H == 0) H = A + B;
        req.insert((H + A - 1) / A - 1);
    }
    int ret = 0;
    for (auto x : req) if (K >= x) K -= x, ret++;
    cout << ret << endl;
}