#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    string pokemon = "Bulbasaur";
    map<char, int> cnt1;
    for (char c : pokemon)
        cnt1[c]++;

    map<char, int> cnt2;
    for (char c : s)
        cnt2[c]++;

    int m = numeric_limits<int>::max();
    for (auto p : cnt1) {
        char c;
        int cnt;
        tie(c, cnt) = p;
        m = min(m, cnt2[c] / cnt);
    }

    cout << m << endl;


    return 0;
}