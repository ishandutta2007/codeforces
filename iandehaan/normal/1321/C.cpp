#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> s;
    vector<char> temp;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    int out = 0;
    char upperbnd = 'z';
    while (true) {
        bool found = false;
        char mx = 'a';
        for (int i = 0; i < n; i++) {
            if (s[i] > mx && s[i] <= upperbnd) {
                mx = s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != mx) continue;
            if (i > 0 && s[i-1] == mx - 1) {
                out++;
                n--;
                temp.clear();
                for (int j = 0; j < n+1; j++) {
                    if (j != i) temp.push_back(s[j]);
                }
                s = temp;
                found = true;
                break;
            }

            if (i < n-1 && s[i+1] == mx - 1) {
                out++;
                n--;
                temp.clear();
                for (int j = 0; j < n+1; j++) {
                    if (j != i) temp.push_back(s[j]);
                }
                s = temp;
                found = true;
                break;
            }
        }

        if (!found) {
            if (mx != 'a') {
                upperbnd--;
            } else {
                break;
            }
        }
    }
    cout << out << endl;
}