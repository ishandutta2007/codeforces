#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp;
    multiset<int> list, gcds;
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        cin >> tmp;
        gcds.insert(tmp);
        };
    for (int i = 0; i < n; ++i) {
        //cerr << gcds.size();
        auto maxit = gcds.find(*(gcds.rbegin()));
        //cerr << "!";
        int maxv = *maxit;
        gcds.erase(maxit);
        for (auto j = list.begin(); j != list.end(); ++j) {
            int val = __gcd(maxv, *j);
            auto it = gcds.lower_bound(val);
            gcds.erase(it);
            it = gcds.lower_bound(val);
            gcds.erase(it);
            };
        list.insert(maxv);
        };
    for (auto j = list.begin(); j != list.end(); ++j) cout << *j << " ";
};