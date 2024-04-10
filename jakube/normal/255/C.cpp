#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<vector<int>> pos(1e6 + 1);

    for (int i = 0; i < n; i++) {
        pos[v[i]].push_back(i);
    }

    vector<int> numbers;
    for (int i = 0; i < pos.size(); i++)
        if (pos[i].size()) numbers.push_back(i);

    int best = 1;
    if (n > 1) {
        for (int num1 : numbers) {
            for (int num2 : numbers) {
                if (num1 == num2) 
                {
                    best = max((int)(pos[num1].size()), best);
                    continue;
                }
                auto it1 = pos[num1].begin();
                auto it2 = pos[num2].begin();
                auto end1 = pos[num1].end();
                auto end2 = pos[num2].end();
                
                while (it2 != end2 && *it1 > *it2) {
                    ++it2;
                }

                if (it2 == end2) continue;

                int cnt = 2;
                while (it1 != end1 && it2 != end2) {
                    ++it1;
                    while (it1 != end1 && *it1 < *it2) {
                        ++it1;
                    }
                    if (it1 == end1) break;
                    cnt++;

                    ++it2;
                    while (it2 != end2 && *it1 > *it2) {
                        ++it2;
                    }
                    if (it2 == end2)
                        break;
                    cnt++;
                }

                best = max(best, cnt);
            }
        }
    }

    cout << best << endl;
                
    return 0;
}