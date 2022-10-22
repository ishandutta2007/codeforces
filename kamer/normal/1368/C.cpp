#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << 8 + 7 * n << "\n";
    cout << "0 0\n-1 0\n0 -1\n-2 0\n0 -2\n-1 -2\n-2 -1\n-2 -2\n";
    for (int i = 0; i < 2 * n; i += 2) {
        cout << i << " " << i + 1 << "\n";
        cout << i + 1 << " " << i << "\n";
        cout << i << " " << i + 2 << "\n";
        cout << i + 2 << " " << i << "\n";
        cout << i + 1 << " " << i + 2 << "\n";
        cout << i + 2 << " " << i + 1 << "\n";
        cout << i + 2 << " " << i + 2 << "\n";
    }
}