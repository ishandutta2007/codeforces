#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll n, r;
        cin >> n >> r;
        ll cool = min(n - 1, r);
        ll res = cool * (cool + 1) / 2;
        if (r >= n) res++;
        cout << res << "\n";
    }
}