#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string ss;
    cin >> ss;

    int f = -1, s = -1, ret = 4, ef = -1, es = -1;

    for (int i=0; i<ss.length(); i++) {
        if (ss[i] == '[') if (f == -1) f = i;
        if (ss[i] == ':') if (f != -1 && s == -1) s = i;
    }

    for (int i=ss.length(); i>s; i--) {
        if (ss[i] == ']') if (ef == -1) ef = i;
        if (ss[i] == ':') if (ef != -1 && es == -1) es = i;
    }

    if (f == -1 || s == -1 || ef == -1 || es == -1) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i=s+1; i<es; i++) {
        if (ss[i] == '|') ret++;
    }

    //cout << f << ' ' << s << ' ' << ef << ' ' << es << '\n';
    cout << ret << '\n';

    return 0;
}