#include <bits/stdc++.h>
using namespace std;

bool has_odd(vector<int> const& v) {
    for (int x : v) {
        if (x & 1)
            return true;
    }
    return false;
}

vector<int> divide(vector<int> const& v, int sub) {
    vector<int> ret;
    for (int x : v) {
        if (x & 1)
            x -= sub;
        x = x / 2;
        if (x && (ret.empty() || ret.back() != x))
            ret.push_back(x);
    }
    return ret;
}

vector<int> f(vector<int> numbers, int power) {
    if (numbers.empty()) {
        return {};
    }
    if (numbers.size() == 1 && (numbers[0] == 1 || numbers[0] == -1)) {
        vector<int> ret;
        if (numbers[0] == 1) {
            ret.push_back(1 << power);
        } else {
            ret.push_back(-(1 << power));
        }
        return ret;
    }
    
    if (has_odd(numbers)) {
        auto a = divide(numbers, 1);
        auto b = divide(numbers, -1);
        auto A = f(a, power+1);
        auto B = f(b, power+1);
        if (A.size() < B.size()) {
            A.push_back(1 << power);
            return A;
        } else {
            B.push_back(-(1 << power));
            return B;
        }
    }

    auto a = divide(numbers, 0);
    return f(a, power + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    auto res = f(v, 0);
    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << endl;
}