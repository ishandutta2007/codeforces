#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<string, string>> strings_per_length(n);
    vector<pair<int, int>> ids_per_length(n);
    for (int i = 0; i < 2*n - 1; i++) {
        string x;
        cin >> x;
        auto& pair = strings_per_length[x.size()];
        auto& ids = ids_per_length[x.size()];
        if (pair.first.empty()) {
            pair.first = x;
            ids.first = i;
        } else {
            pair.second = x;
            ids.second = i;
        }
    }
    
    vector<string> possible_strings;
    auto smallests = strings_per_length[1];
    auto longests = strings_per_length[n-1];
    possible_strings.push_back(longests.first + smallests.first);
    possible_strings.push_back(longests.first + smallests.second);
    possible_strings.push_back(smallests.first + longests.first);
    possible_strings.push_back(smallests.second + longests.first);

    for (string const& p : possible_strings) {
        string answer(2*n - 2, '?');
        bool possible = true;
        for (int i = 1; i < n; i++) {
            string prefix = p.substr(0, i);
            string suffix = p.substr(n-i);
            auto const& currents = strings_per_length[i];
            auto const& ids = ids_per_length[i];
            if (currents == make_pair(prefix, suffix)) {
                answer[ids.first] = 'P';
                answer[ids.second] = 'S';
            } else if (currents == make_pair(suffix, prefix)) {
                answer[ids.first] = 'S';
                answer[ids.second] = 'P';
            } else {
                possible = false;
            }
        }
        if (possible) {
            cout << answer << '\n';
            return 0;
        }
    }
}