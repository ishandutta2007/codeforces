#include <bits/stdc++.h>
using namespace std;
set<int> s {
    1,
    2,
    4,
    5,
    9,
    10,
    20,
    21,
    41,
    42,
    84,
    85,
    169,
    170,
    340,
    341,
    681,
    682,
    1364,
    1365,
    2729,
    2730,
    5460,
    5461,
    10921,
    10922,
    21844,
    21845,
    43689,
    43690,
    87380,
    87381,
    174761,
    174762,
    349524,
    349525,
    699049,
    699050
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << s.count(n) << "\n";
    return 0;
}