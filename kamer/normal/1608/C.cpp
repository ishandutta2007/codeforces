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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<tuple<int, int, int>> players(n);
        for (int i = 0; i < n; i++) players[i] = { a[i], b[i], i };

        sort(players.begin(), players.end());

        sort(b.begin(), b.end());


        unordered_map<int, int> players_b_index;
        for (int i = 0; i < n; i++) {
            auto [ai, bi, ii] = players[i];
            players_b_index[bi] = i;
        }

        vector<int> next(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            next[players_b_index[b[i + 1]]] = players_b_index[b[i]];
        }

        vector<bool> winner(n, false);
        
        int base_index = 0;
        while (base_index < n && next[base_index] == base_index - 1) {
            base_index++;
        }

        int curr_index = base_index;
        int curr_max = -1;

        while (curr_index < n) {
            curr_max = max(curr_max, next[curr_index]);

            if (curr_max == n - 1) {
                for (int i = base_index; i < n; i++) {
                    winner[get<2>(players[i])] = true;
                }
                break;
            } else if (curr_max <= curr_index) {
                base_index = curr_index + 1;
                curr_max = -1;
            }
            
            curr_index++;
        }

        winner[get<2>(players[n - 1])] = true;

        for (int i = 0; i < n; i++) {
            if (winner[i]) cout << "1";
            else cout << "0";
        }

        cout << "\n";
    }
}