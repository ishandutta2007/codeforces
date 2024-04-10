#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), posA(n + 1), posB(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        posA[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        posB[b[i]] = i;
    }

    vector<int> count(n, 0);
    for (int i = 0; i < n; i++) {
        count[(posB[a[i]] - i + n) % n]++;
    }

    int maxim = -1;
    for (int i = 0; i < n; i++) {
        if (maxim < count[i]) maxim = count[i];
    }

    cout << maxim << "\n";
}