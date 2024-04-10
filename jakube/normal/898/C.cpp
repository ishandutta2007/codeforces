#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<string, vector<string>> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            string numb;
            cin >> numb;
            m[name].push_back(numb);
        }
    }

    cout << m.size() << endl;
    for (auto& entry : m) {
        set<string> reduced;
        for (auto& s : entry.second) {
            bool b = true;
            for (auto& t : entry.second) {
                if (s.size() < t.size() && t.substr(t.size() - s.size()) == s) {
                    b = false;
                    break;
                }
            }
            if (b)
                reduced.insert(s);
        }
        cout << entry.first << " " << reduced.size();
        for (auto& s : reduced) {
            cout << " " << s;
        }
        cout << '\n';
    }
}