#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int sum = 0, i = 1;
        for (i = 1; sum < N; i++) sum += i * 2 - 1;
        cout << i - 1 << '\n';
    }
}