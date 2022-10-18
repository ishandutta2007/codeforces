#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    string t;
    cin >> t;

    array<int, 26> needed = {};
    array<int, 26> here = {};
    int qs = 0;
    for (char c : t)
        needed[c - 'a']++;

    vector<char> qms;

    for (char c : s) {
        if (c != '?') {
            here[c - 'a']++;
        }
        else {
            qs++;
        }
    }

    long long L = 0;
    long long R = s.size() + 1;
    while (L + 1 < R) {
        long long M = (L + R) / 2;

        long long available = 0;
        for (int i = 0; i < 26; i++) {
            long long tmp = M * needed[i];
            if (tmp > here[i])
                available += tmp - here[i];
        }

        if (available <= qs)
            L = M;
        else
            R = M;
    }

    for (int i = 0; i < 26; i++) {
        long long tmp = L * needed[i];
        while (tmp > here[i]) {
            here[i]++;
            qms.push_back('a' + i);
        }
    }

    int idx = 0;
    for (char c : s) {
        if (c == '?') {
            if (idx == qms.size())
                cout << "a";
            else {
                cout << qms[idx];
                idx++;
            }
        } else {
            cout << c;
        }
    }
    cout << endl;
}