#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    int n = s.size();
    bool special = true;
    if (s[0] != '1')
        special = false;
    if (s[n-1] > '1')
        special = false;
    for (int i = 1; i < n-1; i++) {
        if (s[i] != '0')
            special = false;
    }
    
    if (special) {
        string t;
        t.resize(n - 2);
        for (int i = 0; i < n-2; i++) {
            t[i] = '9';
        }
        if (t.empty())
            return "0";
        return t;
    }

    vector<int> chars(n);
    for (int i = 0; i < n; i++)
        chars[i] = s[i] - '0';
    for (int i = n-1; i >= 0; i--) {
        chars[i]--;
        if (chars[i] < 0) {
            chars[i] = 9;
        } else {
            break;
        }
    }


    vector<bool> used(10, 0);
    int unpaired = 0;
    vector<int> result(n);
    auto fill_rem = [&](int& i) {
        int remaining = n - i - 1;
        int ccc = 0;
        for (auto b : used)
            ccc += b;

        for (int xyz = 0; xyz < remaining - ccc; xyz++) {
            i++;
            result[i] = 9;
        }

        i++;
        for (int j = 9; j >= 0; j--) {
            if(used[j]) {
                result[i] = j;
                i++;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        int remaining = n - i;
        if (unpaired == remaining) {
            if (used[chars[i]]) {
                // try picking ==;
                used[chars[i]] = false;
                result[i] = chars[i];
                unpaired--;
            } else {
                // pick < and used;
                int c = chars[i]; 
                while (c >= 0 && !used[c]) {
                    c--;
                }
                if (c < 0) {
                    // rewind
                    while (true) {
                        i--;
                        c = result[i];
                        if (used[c]) {
                            used[c] = false;
                            unpaired--;
                        } else {
                            used[c] = true;
                            unpaired++;
                        }
                        remaining++;

                        if (used[result[i]] && unpaired == remaining) {
                            c = result[i] - 1;
                            while (c >= 0 && !used[c])
                                c--;
                            if (c >= 0) {
                                result[i] = c;
                                used[c] = false;
                                fill_rem(i);
                                break;
                            }
                        } else {
                            c = result[i] - 1;
                            if (c >= 0) {
                                result[i] = c;
                                used[c] = !used[c];
                                fill_rem(i);
                                break;
                            }
                        }
                    }
                    // return "";
                } else {
                    result[i] = c;
                    used[c] = false;
                    unpaired--;
                    fill_rem(i);
                    break;
                }
            }
        } else {
            char c = chars[i];
            if (used[c]) {
                used[c] = false;
                unpaired--;
            } else {
                used[c] = true;
                unpaired++;
            }
            result[i] = c;
        }
    }
    string t;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        t[i] = result[i] + '0';
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T --> 0) {
        string s;
        cin >> s;
        cout << f(s) << '\n';
    }
}