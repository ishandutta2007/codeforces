#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string part1[n];
    string part2[m];
    for (int i = 0; i < n; i++) cin >> part1[i];
    for (int i = 0; i < m; i++) cin >> part2[i];

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;

        y--;
        int p1index = y % n;
        int p2index = y % m;
        cout << part1[p1index] << part2[p2index] << endl;
    }
}