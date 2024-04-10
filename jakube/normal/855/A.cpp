#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    int n;
    cin >> n;
    while (n --> 0) {
        string name;
        cin >> name;
        if (s.count(name)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            s.insert(name);
        }
    }
}