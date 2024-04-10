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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    
    vector<pair<int, char>> result;

    if (accumulate(v.begin(), v.end(), 0LL) != accumulate(w.begin(), w.end(), 0LL)) {
        cout << "NO" << endl;
        return 0;
    }

    int b_idx = 0;
    int left = 0;
    int sum = 0;
    int delete_cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum > w[b_idx]) {
            cout << "NO" << endl;
            return 0;
        }
        
        if (sum == w[b_idx]) {
            if (i > left) {
                int max_val = *max_element(v.begin() + left, v.begin() + i + 1);
                bool b = false;
                for (int j = left; j <= i; j++) {
                    if (v[j] == max_val && j > left && v[j-1] < v[j]) {
                        while (j - delete_cnt > b_idx) {
                            result.push_back({j - delete_cnt, 'L'});
                            delete_cnt++;
                        }
                        while (j < i) {
                            result.push_back({j - delete_cnt, 'R'});
                            delete_cnt++;
                            j++;
                        }
                        b = true;
                        break;
                    }
                    if (v[j] == max_val && j < i && v[j] > v[j+1]) {
                        while (j < i) {
                            result.push_back({j - delete_cnt, 'R'});
                            delete_cnt++;
                            j++;
                        }
                        while (j - delete_cnt > b_idx) {
                            result.push_back({j - delete_cnt, 'L'});
                            delete_cnt++;
                        }
                        b = true;
                        break;
                    }
                }

                if (!b) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            left = i + 1;
            sum = 0;
            b_idx++;
        }
    }

    cout << "YES" << '\n';
    for (auto i : result) {
        cout << i.first + 1 << ' ' << i.second << '\n';
    }
}