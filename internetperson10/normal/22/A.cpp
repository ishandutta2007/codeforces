#include <bits/stdc++.h>

using namespace std;

set<int> s;
int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    s.erase(s.begin());
    if(s.size()) cout << *(s.begin()); //
    else cout << "NO\n";
}