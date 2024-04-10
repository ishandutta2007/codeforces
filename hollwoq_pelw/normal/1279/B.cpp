#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    long long S;
    cin >> N >> S;
    vector<long long> A(N);

    for (auto &a : A)
        cin >> a;

    int best = -1, best_index = -1;
    long long sum = 0, maximum = -1;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        if (A[i] > maximum) {
            maximum = A[i];
            max_index = i;
        }

        if (sum <= S && i + 1 > best) {
            best = i + 1;
            best_index = -1;
        }

        if (sum - maximum <= S && i > best) {
            best = i;
            best_index = max_index;
        }
    }

    cout << best_index + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}