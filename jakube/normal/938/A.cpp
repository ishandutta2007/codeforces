#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    string v = "aeiouy";
    return v.find(c) != v.npos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    char last_c = '_';
    for (char c : s) {
        if (is_vowel(c)) {
            if (!is_vowel(last_c)) {
                cout << c;
                last_c = c;
            }
        } else {
            cout << c;
            last_c = c;
        }
    }
    cout << endl;
}