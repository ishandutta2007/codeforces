#include "bits/stdc++.h"

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int ask(vector<int> a) {
    cout << "? " << (int) a.size() << " ";
    for (auto x : a) cout << x << " ";
    cout << endl;
    string s;
    cin >> s;
    if (s == "YES") return 1;
    return 0;
}

void ask(int x) {
    cout << "! " << x << endl;
    string res;
    cin >> res;
    if (res == ":)") {
        exit(0);
    }
}

vector<int> operator+(vector<int> a, vector<int> b) {
    vector<int> c((int) a.size() + (int) b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    return c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    while ((int) a.size() >= 4) {
        vector<int> b[4];
        for (int i = 0; i < (int) a.size(); i++) {
            b[i % 4].push_back(a[i]);
        }
        int l = ask(b[0] + b[1]), r = ask(b[1] + b[2]);
        int j = 0;
        if (l == 1 && r == 1) {
            j = 3;
        }
        if (l == 1 && r == 0) {
            j = 2;
        }
        if (l == 0 && r == 1) {
            j = 0;
        }
        if (l == 0 && r == 0) {
            j = 1;
        }
        set<int> A;
        for (int i = 0; i < 4; i++) {
            if (i != j) {
                for (auto x : b[i]) A.insert(x);
            }
        }
        a = vector<int>(A.begin(), A.end());
    }
    if ((int) a.size() <= 2) {
        ask(a[0]);
        ask(a[1]);
    }
    int x = a[0], y = a[1], z = a[2];
    vector<int> Y = {y};
    auto A = ask(Y);
    auto B = ask(Y);
    if (A == B) {
        if (A == 1) {
            ask(y);
        } else {
            ask(x);
            ask(z);
        }
    }
    if (B == 0) {
        A = ask(Y);
        if (A == 0) {
            ask(x), ask(z);
        }
    }
    A = ask({x, y});
    B = ask({y, z});
    if (A == 1 && B == 0) {
        ask(x);
        ask(y);
    }
    if (A == 0 && B == 1) {
        ask(y);
        ask(z);
    }
    if (A == 0 && B == 0) {
        ask(x);
        ask(z);
    }
    if (A == 1 && B == 1) {
        ask(y);
        ask(x);
    }
}