#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int t;
    cin >> t;
    unordered_set<int> st;
    for (int i = 1; i * i <= 1e9 + 10; i++) {
        st.insert(i * i);
    }
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0 && st.count(n / 2)) cout << "YES" << endl;
        else if (n % 4 == 0 && st.count(n / 4)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}