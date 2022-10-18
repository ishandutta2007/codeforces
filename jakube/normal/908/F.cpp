#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int last_green = -1;
    array<vector<int>, 2> positions;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        char c;
        cin >> c;
        if (c == 'R') {
            positions[0].push_back(p);
        } else if (c == 'B') {
            positions[1].push_back(p);
        } else {
            if (last_green == -1) {
                for (auto& pos : positions) {
                    if (pos.size())
                        sum += p - pos.front();
                }
            } else {
                int dist = p - last_green;
                array<int, 2> single = {{0, 0}};
                for (int k = 0; k < 2; k++) {
                    auto& pos = positions[k];
                    if (pos.size()) {
                        single[k] = min(p - pos.front(), pos.back() - last_green);
                        for (int j = 0; j < (int)pos.size() - 1; j++) {
                            single[k] = min(single[k], dist - pos[j+1] + pos[j]);
                        }
                    }
                }
                sum += min(dist + single[0] + single[1], 2 * dist);
            }

            positions[0].clear();
            positions[1].clear();
            last_green = p;
        }
    }

    for (auto& pos : positions) {
        if (pos.size())
            sum +=  pos.back() - (last_green > 0 ? last_green : pos.front());
    }
    
    cout << sum << '\n';
}