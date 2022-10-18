#include <bits/stdc++.h>
using namespace std;

auto mypow = [](int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<pair<int, bool>> cnts(10, {0, false});
    for (auto& s : v) {
        cnts[s[0] - 'a'].second = true;
        for (int i = 0; i < (int)s.size(); i++) {
            cnts[s[i] - 'a'].first += mypow(10, s.size() - 1 - i);
        }
    }

    int sum = 0;
    sort(cnts.begin(), cnts.end());
    reverse(cnts.begin(), cnts.end());
    for (auto& p : cnts) {
        if (!p.second) {
            p.first = 0;
            break;
        }
    }
    sort(cnts.begin(), cnts.end());
    reverse(cnts.begin(), cnts.end());
    int num = 1;
    for (int i = 0; i < 10; i++) {
        if (cnts[i].first) {
            sum += cnts[i].first * num;
            num++;
        }
    }
    cout << sum << '\n';
}