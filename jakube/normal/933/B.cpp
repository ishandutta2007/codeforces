#include <bits/stdc++.h>
using namespace std;

std::vector<int> to_negative_base(long long x, int pos_base) {
    std::vector<int> coeff;
    while (x) {
        int rem = x % pos_base;
        if (rem < 0) rem += pos_base;
        coeff.push_back(rem);
        x -= rem;
        x /= -pos_base;
    }
    return coeff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p;
    cin >> p;
    int k;
    cin >> k;

    auto coeff = to_negative_base(p, k);
    cout << (int)coeff.size() << endl;
    for (auto x : coeff) {
        cout << x << ' ';
    }
    cout << endl;
}