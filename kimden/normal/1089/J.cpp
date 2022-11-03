#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<string> reserved;
unordered_set<string> rest;
unordered_map<string, string> mp;
string nxt = "a";

int comp_s(const string& a, const string& b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() > b.size();
}

string get_canon(string s) {
    if (rest.count(s))
        return s;
    int dig = 1;
    for (char c : s)
        dig &= isdigit(c);
    if (dig)
        return s;
    if (mp[s].size() == 0) {
        while (rest.count(nxt)) {
            int carry = 1;
            for (int i = (int)nxt.size(); i--; ) {
                nxt[i] += carry;
                carry = 0;
                if (nxt[i] > 'z') {
                    nxt[i] = 'a';
                    carry = 1;
                }
            }
            if (carry)
                nxt = "a" + nxt;
        }
        mp[s] = nxt;
        for (int i = 0; i < 1; ++i) {
            int carry = 1;
            for (int i = (int)nxt.size(); i--; ) {
                nxt[i] += carry;
                carry = 0;
                if (nxt[i] > 'z') {
                    nxt[i] = 'a';
                    carry = 1;
                }
            }
            if (carry)
                nxt = "a" + nxt;
        }
    }
    return mp[s];
}

vector<pair<bool, string>> parse(string s) {
    int idx = s.find("#");
    if (idx != -1) {
        s = s.substr(0, idx);
    }
    vector<pair<bool, string>> res;
    idx = 0;
    bool was_space = true;
    while (idx < s.size()) {
        if (s[idx] == ' ') {
            ++idx;
            was_space = true;
            continue;
        }
        int possible_length = -1;
        for (int i = 0; i < reserved.size(); ++i) {
            if (idx + reserved[i].size() <= s.size() && s.substr(idx, reserved[i].size()) == reserved[i]) {
//                res.push_back(make_pair(was_space, reserved[i]));
//                idx += reserved[i].size();
                was_space = false;
                possible_length = reserved[i].size();
                break;
            }
        }
        if (isdigit(s[idx])) {
            int o = idx;
            while (isdigit(s[o]))
                ++o;
            if (o - idx > possible_length) {
                possible_length = o - idx;
//                res.push_back(make_pair(was_space, cur));
                was_space = false;
            }
        }
        if (isalpha(s[idx]) || s[idx] == '$' || s[idx] == '_') {
            int o = idx;
            while (isalnum(s[o]) || s[o] == '$' || s[o] == '_')
                ++o;
            if (o - idx > possible_length) {
                possible_length = o - idx;
//                res.push_back(make_pair(was_space, cur));
                was_space = false;
//                continue;
            }
        }
        res.push_back(make_pair(was_space, s.substr(idx, possible_length)));
        idx += possible_length;
        was_space = false;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        reserved.push_back(s);
        rest.insert(s);
    }

    sort(all(reserved), comp_s);

    int m;
    cin >> m;
    string s;
    getline(cin, s);
    vector<pair<bool, string>> tokens, res;
    while (m--) {
        getline(cin, s);
        auto my = parse(s);
        for (auto x : my)
            tokens.push_back(x);
    }

    string ans = "";
    for (int i = 0; i < (int)tokens.size(); ++i) {
        tokens[i].second = get_canon(tokens[i].second);
    }

    while (tokens.size() > 1) {
        string b = tokens.back().second; tokens.pop_back();
        string a = tokens.back().second; tokens.pop_back();
        bool word = isalpha(a[0]) || a[0] == '$' || a[0] == '_';
        for (int i = 1; a[i]; ++i)
            word &= isalnum(a[i]) || a[i] == '$' || a[i] == '_';
        if (word && (isalnum(b[0]) || b[0] == '$' || b[0] == '_')) {
            tokens.push_back(make_pair(0, a + " " + b));
            continue;
        }
        bool dig = true;
        for (int i = 0; a[i]; ++i)
            dig &= isdigit(a[i]);
        if (dig && isdigit(b[0])) {
            tokens.push_back(make_pair(0, a + " " + b));
            continue;
        }
        string x = a;
        x.push_back(b[0]);
        int idx = 1;
        bool need_space = false;
        while (true) {
            if (rest.count(x)) {
                need_space = true;
                break;
            }
            if (b[idx] == 0 || b[idx] == ' ')
                break;
            x += b[idx++];
            if(x.size() > 20){
                break;
            }
        }
        if (need_space) {
            tokens.push_back(make_pair(0, a + " " + b));
        } else {
            tokens.push_back(make_pair(0, a + b));
        }
    }

    cout << tokens.back().second << endl;
}
/**
10
( ) + ++ : -> >> >>: b c)
2
($val1++ + +4 kb) >> :out
b-> + 10 >>: t # using >>:
*/