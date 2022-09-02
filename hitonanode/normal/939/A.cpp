#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> F(N);
    for (auto &x : F) cin >> x, x--;
    for (int i = 0; i < N; ++i) {
        int j = F[i], k = F[j];
        if (F[k] == i) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}