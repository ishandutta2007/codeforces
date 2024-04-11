#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n;
    cin >> n;

    vector<int> a;
    while (n--) {
        a.push_back(1);
        while (a.size() > 1) {
            if (a[int(a.size()) - 1] == a[int(a.size()) - 2]) {
                a.pop_back();
                a.back() += 1;
            } else break;
        }
    }

    for (int x : a) {
        printf("%d ", x);
    }
    cout << endl;

    return 0;
}