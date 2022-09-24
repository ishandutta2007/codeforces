#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        set<string> st;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            string t = "";
            for (int j = 0; j < (int)s.length(); j++) {
                int c = j;
                int cnt = 0;
                while (c < (int)s.length() && (s[c] == 'u' || s[c] == 'o')) {
                    if (s[c] == 'u') cnt += 2;
                    if (s[c] == 'o') cnt += 1;
                    c++;
                }
                if (cnt > 0) {
                    j = c - 1;
                    for (int p = 0; p < cnt / 2; p++) t += 'u';
                    if (cnt % 2) t += 'o';
                    continue;
                }
                int l = j;
                while (l < (int)s.length() && s[l] == 'k') l++;
                if (l < (int)s.length() && s[l] == 'h') {
                    t += 'h';
                    j = l;
                    continue;
                }
                t += s[j];
            }
            st.insert(t);
        }
        cout << st.size() << endl;
        //for (string s : st) cerr << s << endl;
    }
    
    return 0;
}