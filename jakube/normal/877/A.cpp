#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    vector<string> v = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        auto t = s.substr(i);
        for (auto w : v) {
            if (t.substr(0, w.size()) == w)
                cnt++;
        }
    }
    if (cnt == 1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}