#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);
    }
    
    vector<string> res;
    if (s.count("purple") == 0)
        res.push_back("Power");
    if (s.count("green") == 0)
        res.push_back("Time");
    if (s.count("blue") == 0)
        res.push_back("Space");
    if (s.count("orange") == 0)
        res.push_back("Soul");
    if (s.count("red") == 0)
        res.push_back("Reality");
    if (s.count("yellow") == 0)
        res.push_back("Mind");
        
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << '\n';
    }
}