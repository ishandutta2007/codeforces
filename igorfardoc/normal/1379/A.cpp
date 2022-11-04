#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const string t = "abacaba";

int get_am(string s) {
    int am = 0;
    for(int i = 0; i < (int)s.size() + 1 - t.size(); i++) {
        bool ok = true;
        for(int j = 0; j < t.size(); j++) {
            if(t[j] != s[i + j]) {
                ok = false;
                break;
            }
        }
        am += ok;
    }
    return am;
}

string try_replace(string s, int l) {
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == s[l + i]) {
            continue;
        }
        if(s[l + i] == '?') {
            s[l + i] = t[i];
            continue;
        }
        return "0";
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') {
            s[i] = 'z';
        }
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t1;
    cin >> t1;
    while(t1--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(get_am(s) == 1) {
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '?') {
                    s[i] = 'z';
                }
            }
            cout << "Yes\n" << s << '\n';
            continue;
        }
        if(get_am(s) > 1) {
            cout << "No\n";
            continue;
        }
        bool ok = false;
        for(int i = 0; i < (int)s.size() + 1 - t.size(); i++) {
            string s1 = try_replace(s, i);
            if(s1 != "0" && get_am(s1) == 1) {
                cout << "Yes\n" << s1 << '\n';
                ok = true;
                break;
            }
        }
        if(!ok) {
            cout << "No\n";
        }
    }
}