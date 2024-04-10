#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

    string s(m, '0');
    vector<tuple<ll, int>> weights(m);
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        cout << "? " << s << "\n";
        cout.flush();

        ll edge_weight;
        cin >> edge_weight;
        weights[i] = { edge_weight, i };

        s[i] = '0';
    }

    sort(weights.begin(), weights.end());

    ll curr_sum_weights = 0;
    for (auto [edge_weight, index] : weights) {
        curr_sum_weights += edge_weight;
        s[index] = '1';
        cout << "? " << s << "\n";
        cout.flush();

        ll capacity;
        cin >> capacity;

        if (capacity != curr_sum_weights) {
            curr_sum_weights -= edge_weight;
            s[index] = '0';
        }
    }

    cout << "! " << curr_sum_weights << "\n";
    cout.flush();
}