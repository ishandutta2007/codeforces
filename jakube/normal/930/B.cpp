#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(15);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(2*n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - 'a';
        v[n+i] = s[i] - 'a';
    }

    vector<vector<int>> shifts(26);
    for (int i = 0; i < n; i++) {
        shifts[v[i]].push_back(i);
    }

    double result = 0;
    for (int c = 0; c < 26; c++) {
        if (shifts[c].empty())
            continue;

        int best = 0;
        for (int k = 1; k < n; k++) {
            array<int, 26> cnt;
            cnt.fill(0);
            for (int j : shifts[c]) {
                cnt[v[k + j]]++;
            }
            int unique = 0;
            for (int cc : cnt)
                unique += cc == 1;
            best = max(best, unique);
        }
        result += (double)best / (double)n;
    }
    cout << result << endl;
}