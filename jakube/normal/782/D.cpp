#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        v[i].first = s.substr(0, 3);
        v[i].second = s.substr(0, 2) + t.substr(0, 1);
    }

    map<string, int> m;
    for (auto p : v)
        m[p.first]++;

    vector<string> result(n);
    map<string, int> m2;
    map<string, int> last_idx;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (m[v[i].first] > 1) {
            result[i] = v[i].second;
            m2[v[i].second]++;
            
            int idx = i;
            string word = v[i].second;
            while (m2[word] == 2) {
                idx = last_idx[word];
                if (word == v[idx].second) {
                    possible = false;
                    break;
                }
                last_idx[word] = i;
                m2[word] = 1;

                word = v[idx].second;
                result[idx] = word;
                m2[word]++;
            }

            last_idx[word] = idx;
        }
        else {
            string word = v[i].first;
            result[i] = word;
            m2[word]++;
            int idx = i;

            if (m2[word] == 2) {
                m2[word] = 1;
                word = v[i].second;
                result[i] = word;
                m2[word]++;

                while (m2[word] == 2) {
                    idx = last_idx[word];
                    if (word == v[idx].second) {
                        possible = false;
                        break;
                    }
                    last_idx[word] = i;
                    m2[word] = 1;

                    word = v[idx].second;
                    result[idx] = word;
                    m2[word]++;
                }
            }

            last_idx[word] = idx;
        }
    }

    if (possible) {
        cout  << "YES" << '\n';
        for (auto s : result)
            cout << s << '\n';
    }
    else {
        cout << "NO\n";
    }
}