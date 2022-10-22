#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int q, arr[30], sp;
string s, t, p;
bool flag;

int main() {
    cin >> q;
    while (q--) {
        cin >> s >> t >> p;

        sp = 0;
        memset(arr, 0, sizeof arr);
        flag = false;

        for (int i=0; i<p.size(); i++) {
            arr[p[i]-'a']++;
        }

        for (int i=0; i<t.size(); i++) {
            if (sp<s.size() && t[i] == s[sp]) {
                ++sp;
            }
            else {
                arr[t[i]-'a']--;
            }
        }

        for (int i=0; i<30; i++) {
            if (arr[i]<0) flag = true;
        }

        if (sp < s.size() || flag) cout << "NO";
        else cout << "YES";

        cout << '\n';
    }
}