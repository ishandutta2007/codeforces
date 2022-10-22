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

static inline void reverse(vector<int>& p, int l) {
    for (int i = 0; i < l / 2; i++) {
        int temp = p[i];
        p[i] = p[l - i - 1];
        p[l - i - 1] = temp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        bool impossible = false;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] % 2 == i % 2) {
                impossible = true;
            }
        }

        if (impossible) {
            cout << "-1\n";
            continue;
        }

        vector<int> moves;

        for (int i = 1; i < n; i += 2) {
            int i_pos = -1, j_pos = -1;
            for (int j = 0; j < n; j++) {
                if (p[j] == i) i_pos = j + 1;
                if (p[j] == i + 1) j_pos = j + 1;
            }

            moves.push_back(i_pos);
            reverse(p, i_pos);
            if (j_pos < i_pos) j_pos = i_pos - j_pos + 1;
            i_pos = 1;
            moves.push_back(j_pos - 1);
            reverse(p, j_pos - 1);
            i_pos = j_pos - 1;
            moves.push_back(j_pos + 1);
            reverse(p, j_pos + 1);
            j_pos = 2;
            i_pos = 3;
            moves.push_back(3);
            reverse(p, 3);
            i_pos = 1;
            moves.push_back(n - i + 1);
            reverse(p, n - i + 1);
        }

        moves.push_back(n);

        cout << moves.size() << "\n";
        for (int i = 0; i < moves.size(); i++) {
            cout << moves[i] << " ";
        }
        cout << "\n";
    }
}