#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--) {
        llint a, b, sol = 0;
        cin >> a >> b;
        for (int i = 0; i < b % a; i++) sol += (b / a + 1) * (b / a + 1);
        for (int i = b % a; i < a; i++) sol += (b / a) * (b / a);
        cout << sol << '\n';
    }
    return 0;
}