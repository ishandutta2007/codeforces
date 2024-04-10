#include <bits/stdc++.h>
using namespace std;

class Expression {
public:


    char digit_l = '_';
    char digit_r = '_';
    Expression* l = nullptr;
    Expression* r = nullptr;
};

int n;
string s;
int i;

auto parse_exp() {
    if ('0' <= s[i] && s[i] <= '9') {
        vector<pair<int, int>> v;
        int val = s[i] - '0';
        v.push_back({val, val});
        i++;
        return v;
    }

    i++; // bracket
    auto l = parse_exp();
    i++; // operation
    auto r = parse_exp();
    i++;

    int n1 = l.size();
    int n2 = r.size();
    vector<pair<int, int>> res(n1 + n2);
    for (int j = 0; j < n1 + n2; j++) {
        res[j] = { std::numeric_limits<int>::max(), std::numeric_limits<int>::min() };

        // plus
        for (int k = 0; k < n1 && k < j; k++) {
            auto& x = l[k];
            if (j - k - 1 >= n2) continue;
            auto& y = r[j - k - 1];
            array<int, 4> a{{x.first + y.first, x.first + y.second, x.second + y.second, x.second + y.first}};
            sort(a.begin(), a.end());
            res[j].first = min(res[j].first, a[0]);
            res[j].second = max(res[j].second, a[3]);
        }

        // minus
        for (int k = 0; k < n1 && k <= j; k++) {
            auto& x = l[k];
            if (j - k >= n2) continue;
            auto& y = r[j - k];
            array<int, 4> a{{x.first - y.first, x.first - y.second, x.second - y.second, x.second - y.first}};
            sort(a.begin(), a.end());
            res[j].first = min(res[j].first, a[0]);
            res[j].second = max(res[j].second, a[3]);
        }

    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int p, m;
    cin >> p >> m;
    
    n = s.size();
    if (n == 1) {
        cout << s << endl;
        return 0;
    }

    i = 0;
    auto res = parse_exp();
    cout << res[p].second << endl;
}