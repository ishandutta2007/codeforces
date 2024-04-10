#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    int count = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        deg[a]++;
        if (deg[a] == 1) {
            count++;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 3) {
            cout << n - count << "\n";
        } else {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            if (c == 1) {
                deg[a]++;
                if (deg[a] == 1) count++;
            } else {
                deg[a]--;
                if (deg[a] == 0) count--;
            }
        }
    }
}