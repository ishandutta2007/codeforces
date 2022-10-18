#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<bool> used(s.size(), true);
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0')
            k--;
        else {
            used[i] = false;
            cnt++;
        }

        if (k == 0)
            break;
    }

    string t = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (used[i])
            t += s[i];
    }
    
    if (all_of(t.begin(), t.end(), [](char c){ return c == '0'; }))
        cnt += t.size() - 1;

    cout << cnt << endl;
}