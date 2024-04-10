#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct hero {
    int P, S;

    bool operator < (const hero &other) const {
        if (P != other.P)
            return P > other.P;

        return S > other.S;
    }
};

bool compare_S(hero x, hero y) {
    return x.S < y.S;
}

int N, M;
vector<int> A;
vector<hero> heroes;

void solve_case() {
    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    cin >> M;
    heroes.resize(M);

    for (hero &h : heroes)
        cin >> h.P >> h.S;

    sort(heroes.begin(), heroes.end());

    if (*max_element(A.begin(), A.end()) > heroes[0].P) {
        cout << -1 << '\n';
        return;
    }

    vector<hero> new_heroes;
    int max_S = -1;

    for (hero &h : heroes)
        if (h.S > max_S) {
            max_S = h.S;
            new_heroes.push_back(h);
        }

    heroes = new_heroes;
    M = heroes.size();
    int start = 0, days = 0;

    while (start < N) {
        int monsters = 0, maximum = 0;

        while (start + monsters < N) {
            maximum = max(maximum, A[start + monsters]);
            auto it = lower_bound(heroes.begin(), heroes.end(), hero({0, monsters + 1}), compare_S);

            if (it != heroes.end() && it->P >= maximum)
                monsters++;
            else
                break;
        }

        start += monsters;
        days++;
    }

    cout << days << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}