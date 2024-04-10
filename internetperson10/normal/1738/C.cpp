#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int w[101][101];

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(abs(x) % 2 == 1) a++;
        else b++;
    }
    if(a % 4 == 3) {
        cout << "Alice\n";
    }
    else if(a % 4 == 2) {
        cout << "Bob\n";
    }
    else if(a % 4 == 0) {
        cout << "Alice\n";
    }
    else if(b % 2 == 1) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}