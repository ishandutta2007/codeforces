#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0; i < n+1; i++) {
        cin >> v[i];
    }
    
    auto cp = v;
    bool possible = false;
    for (int i = 0; i < n; i++) {
        if (v[i] > 1 && v[i+1] > 1) {
            possible = true;
        }
    }

    if (possible) {
        cout << "ambiguous" << '\n';

        vector<vector<int>> height_nodes(n+1);
        vector<int> height;
        height_nodes[0].push_back(0);
        height.push_back(0);
        int h = 1;
        for (int i = 1; h < n || (h == n && v[h] > 0); i++) {
            if (v[h] == 0)
                h++;
            height_nodes[h].push_back(i);
            height.push_back(h);
            v[h]--;
        }

        cout << 0 << " ";
        for (int h = 1; h <= n; h++) {
            if (cp[h - 1] > 1 && cp[h] > 1) {
                for (int i = 0; i < (int)height_nodes[h].size(); i++) {
                    cout << 1 + height_nodes[h - 1][i % height_nodes[h-1].size()] << " ";
                }
            } else {
                for (int i = 0; i < (int)height_nodes[h].size(); i++) {
                    cout << 1 + height_nodes[h - 1][0] << " ";
                }
            }
        }
        cout << '\n';
        cout << 0 << " ";
        for (int h = 1; h <= n; h++) {
            for (int i = 0; i < (int)height_nodes[h].size(); i++) {
                cout << 1 + height_nodes[h - 1][0] << " ";
            }
        }

    } else {
        cout << "perfect" << '\n';
    }
}