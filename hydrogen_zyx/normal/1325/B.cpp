#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_set<int> s;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        s.clear();
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        cout << s.size() << endl;
    }
}