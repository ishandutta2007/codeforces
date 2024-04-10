#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    int m = numeric_limits<int>::max();
    int bi;
    int bj;
    int bk;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i+1; j < s.size(); j++) {
            for (int k = j+1; k < s.size(); k++) {
                if (((s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0')) % 8 == 0) {
                    int cost = s.size() - 1 - k;
                    cost += k - j - 1;
                    cost += j - 1 - i;
                    if (cost < m) {
                        m = cost;
                        bi = i;
                        bj = j;
                        bk = k;
                    }
                }
            }

            if (((s[i]-'0')*10 + (s[j]-'0')) % 8 == 0) {
                int cost = s.size() - 1 - j;
                cost += j - 1 - i;
                cost += i;
                if (cost < m) {
                    m = cost;
                    bi = i;
                    bj = j;
                    bk = j;
                }
            }
        }

        if (((s[i]-'0')) % 8 == 0) {
            int cost = s.size() - 1;
            if (cost < m) {
                m = cost;
                bi = i;
                bj = i;
                bk = i;
            }
        }
    }

    if (m < numeric_limits<int>::max()) {
        cout << "YES" << endl;
        if (bi == bj && bj == bk) {
            cout << s[bi] << endl;
        }
        else if (bj == bk) {
            cout << s[bi] << s[bj] << endl;
        }
        else {
            cout << s.substr(0, bi+1) << s[bj] << s[bk] << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
        

    return 0;
}