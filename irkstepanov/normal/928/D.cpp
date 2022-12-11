#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct node {
    int cnt;
    map<char, int> to;
    node() : cnt(0) {}
};

vector<node> t;
int ans = 0;

set<string> setik;

void add(const string& s) {
    if (setik.count(s)) {
        return;
    }
    setik.insert(s);
    int curr = 0;
    ++t[curr].cnt;
    for (int i = 0; i < sz(s); ++i) {
        if (!t[curr].to.count(s[i])) {
            t.pb(node());
            t[curr].to[s[i]] = sz(t) - 1;
        }
        int nx = t[curr].to[s[i]];
        curr = nx;
        ++t[nx].cnt;
    }
}

void solve(const string& s) {
    if (t[0].cnt == 0) {
        ans += sz(s);
        return;
    }
    int curr = 0;
    int i = 0;
    while (i < sz(s) && t[curr].cnt > 1) {
        if (!t[curr].to.count(s[i])) {
            ans += sz(s);
            return;
        }
        curr = t[curr].to[s[i]];
        ++i;
    }
    if (i == sz(s)) {
        ans += sz(s);
        return;
    }
    if (curr == 0) {
        auto it = t[curr].to.begin();
        if (it->first != s[i]) {
            ans += sz(s);
            return;
        }
        curr = it->second;
        ++i;
    }
    int eco = 0;
    while (!t[curr].to.empty()) {
        if (i == sz(s)) {
            ans += sz(s);
            return;
        }
        auto it = t[curr].to.begin();
        if (it->first != s[i]) {
            ans += sz(s);
            return;
        }
        ++eco;
        curr = it->second;
        ++i;
    }
    ans += min(sz(s), sz(s) - eco + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    t.pb(node());

    string s;

    while(getline(cin, s)) {
        ++ans; // carry
        for (int i = 0; i < sz(s); ++i) {
            if (!isalpha(s[i])) {
                ++ans;
            }
        }
        vector<string> words;
        string curr = "";
        for (int i = 0; i < sz(s); ++i) {
            if (isalpha(s[i])) {
                curr += s[i];
            } else if (curr != "") {
                words.pb(curr);
                curr = "";
            }
        }
        if (curr != "") {
            words.pb(curr);
        }
        for (int i = 0; i < sz(words); ++i) {
            solve(words[i]);
            add(words[i]);
        }
    }

    cout << ans << "\n";

}