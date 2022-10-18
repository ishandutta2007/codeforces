#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if (k == 2) {
        string t = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            t += (i & 1) ? 'A' : 'B';
            if (s[i] != t[i]) cnt++;
        }

        string t2 = "";
        int cnt2 = 0;
        for (int i = 0; i < s.size(); i++) {
            t2 += (i & 1) ? 'B' : 'A';
            if (s[i] != t2[i]) cnt2++;
        }

        if (cnt < cnt2) cout << cnt << endl << t << endl;
        else cout << cnt2 << endl << t2 << endl;
        return 0;
    }

    string t = "";
    t += s[0];
    int cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if (t[i-1] == s[i]) {
            for (char k = 'A'; k < 'Z'; k++) {
                if (t[i-1] != k && (i >= s.size()-1 || s[i+1] != k)) {
                    t += k;
                    break;
                }
            }
            cnt++;
        }
        else t += s[i];
    }

    cout << cnt << endl << t << endl;
    


    return 0;
}