#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    vector<char> s(x.begin(), x.end());
    vector<char> t(y.begin(), y.end());
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x != y) {
        cout << -1 << endl;
        return 0;
    }

    auto find_back = [&s,n](char c) {
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == c)
                return i;
        }
        return -1;
    };
    vector<int> shifts;
    auto shift = [&s,n,&shifts](int x) {
        shifts.push_back(x);
        reverse(s.end() - x, s.end());
        rotate(s.begin(), s.begin() + (n - x), s.end());
    };

    vector<int> order;
    int start = n / 2;
    for (int i = 0; i < n; i++) {
        order.push_back(start + (i % 2 ? -(i+1)/2 : i/2));
    }

    int fixed = 0;
    for (int cur : order) {
        int pos = find_back(t[cur]);
        int many = n - pos;
        shift(many);
        fixed++;
        int tail = n - fixed - (many - 1);
        shift(tail);
        shift(n);
    }

    if (n % 2 == 0)
        shift(n);

    cout << shifts.size() << endl;
    for (auto x : shifts) {
        cout << x << ' ';
    }
    cout << endl;
}