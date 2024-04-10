#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> s;

    int n, a, b;
    cin >> n >> a >> b;
    for (int x=a; x<=n-1; x++) {
        for (int y=0; y<=b; y++) {
            if (x + y == n-1)
                s.insert(x);
        }
    }

    cout << s.size() << '\n';
}