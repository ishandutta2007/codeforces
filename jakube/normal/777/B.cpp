#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string S, t;
    cin >> S >> t;
    
    vector<int> sherlock(10, 0), moriarty(10, 0);
    for (char c : S)
        sherlock[c - '0']++;
    for (char c : t)
        moriarty[c - '0']++;

    int ps = 0, pm = 0;
    vector<int> s(sherlock), m(moriarty);
    for (int i = 9; i >= 0; i--) {
        pm += m[i];
        int tmp = min(s[i], pm);
        s[i] -= tmp;
        pm -= tmp;
        ps += s[i];
    }
    cout << ps << endl;

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int idx_m = i + 1;
        while (sherlock[i] && idx_m < 10) {
            if (moriarty[idx_m] == 0)
                idx_m++;
            else {
                sherlock[i]--;
                cnt++;
                moriarty[idx_m]--;
            }
        }
    }

    cout << cnt << endl;
}