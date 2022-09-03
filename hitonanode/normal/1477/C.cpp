#include <iostream>
using namespace std;

long long X[5000], Y[5000];
int alive[5000];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    auto D2 = [&](int i, int j) {
        auto dx = X[i] - X[j], dy = Y[i] - Y[j];
        return dx * dx + dy * dy;
    };

    fill(begin(alive), end(alive), 1);

    auto farthest = [&](int i) -> int {
        int ret = i;
        long long dtmp = -1;
        for (int j = 0; j < N; j++) {
            if (alive[j]) {
                auto d = D2(i, j);
                if (d >= dtmp) ret = j, dtmp = d;
            }
        }
        return ret;
    };

    int now = farthest(0);
    while (alive[now]) {
        cout << now + 1 << ' ';
        alive[now] = 0;
        now = farthest(now);
    }
    cout << '\n';
}