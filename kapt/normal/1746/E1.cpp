#include <bits/stdc++.h>
using namespace std;

/// #define set unordered_set

bool ask(const set<int> &s) {
    cout << "? " << s.size() << " ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    string st;
    cin >> st;
    return st == "YES";
}

set<int> get(const set<int> &all, const set<int> &st) {
    set<int> ans;
    for (auto elem : all) {
        if (!st.count(elem)) {
            ans.insert(elem);
        }
    }
    return ans;
}

void ans(int x) {
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if (s == ":)") exit(0);
}

main() {
    int n;
    cin >> n;
    set<int> val;
    for (int i = 1; i <= n; ++i) {
        val.insert(i);
    }
    set<int> s;
    for (int i = 1; i <= n / 2; ++i) {
        s.insert(i);
    }
    if (!ask(s)) {
        s = get(val, s);
    }
    while (val.size() > 4) {
        set<int> t;
        for (auto elem : s) {
            if (t.size() * 2 + 2 <= s.size()) {
                t.insert(elem);
            } else {
                break;
            }
        }
        for (auto elem : val) {
            if (s.count(elem)) continue;
            if (t.size() * 2 + 2 <= val.size()) {
                t.insert(elem);
            } else {
                break;
            }
        }
        if (!ask(t)) {
            t = get(val, t);
        }
        val.clear();
        for (auto elem : s) {
            val.insert(elem);
        }
        for (auto elem : t) {
            val.insert(elem);
        }
        s = t;
    }
    if (val.size() == 4 && s.size() <= 2) {
        set<int> t;
        t.insert(*s.begin());
        t.insert(*get(val, s).begin());
        if (!ask(t)) t = get(val, t);
        val.clear();
        for (auto elem : s) {
            val.insert(elem);
        }
        for (auto elem : t) {
            val.insert(elem);
        }
    } else if (val.size() == 4) {
        vector<int> arr;
        for (auto x : val) {
            arr.push_back(x);
        }
        set<int> a, b;
        a.insert(arr[0]);
        a.insert(arr[1]);
        b.insert(arr[0]);
        b.insert(arr[2]);
        if (!ask(a)) a = get(val, a);
        if (!ask(b)) b = get(val, b);
        val.clear();
        for (auto elem : a) {
            val.insert(elem);
        }
        for (auto elem : b) {
            val.insert(elem);
        }
    }
    if (val.size() == 3) {
        int x = *val.begin();
        set<int> s;
        s.insert(x);
        if (!ask(s) && !ask(s)) {
            val.erase(x);
        } else {
            ans(x);
            val.erase(x);
            s.clear();
            s.insert(*val.begin());
            if (ask(s)) {
                ans(*val.begin());
            } else {
                val.erase(val.begin());
                ans(*val.begin());
            }
            return 0;
        }
    }
    for (auto x : val) ans(x);
    return 0;
}