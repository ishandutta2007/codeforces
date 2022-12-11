#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll nmax = 1 << 15;

void add(int& a, int b) {
    a += b;
    if (a >= nmax) {
        a -= nmax;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += nmax;
    }
}

void mul(int& a, int b) {
    a *= b;
    if (a >= nmax) {
        a %= nmax;
    }
}

int result[nmax];
vector<char> program;

int get(const string& s) {
    //cout << s << "\n";
    bool number = true;
    int val = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            number = false;
            break;
        } else {
            val *= 10;
            val += s[i] - '0';
        }
    }
    if (number) {
        return val;
    }
    if (s[0] == '(') {
        int balance = 1;
        bool brackets = true;
        for (int i = 1; i < sz(s) - 1; ++i) {
            if (s[i] == '(') {
                ++balance;
            } else if (s[i] == ')') {
                --balance;
            }
            if (balance == 0) {
                brackets = false;
                break;
            }
        }
        if (brackets) {
            return get(s.substr(1, sz(s) - 2));
        }
    }
    int balance = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '(') {
            ++balance;
        } else if (s[i] == ')') {
            --balance;
        }
        if (balance == 0 && s[i] == '+') {
            int a = get(s.substr(0, i));
            add(a, get(s.substr(i + 1, sz(s) - i - 1)));
            return a;
        }
    }
    balance = 0;
    vector<int> pos;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '(') {
            ++balance;
        } else if (s[i] == ')') {
            --balance;
        }
        if (balance == 0 && s[i] == '-') {
            pos.pb(i);
        }
    }
    if (!pos.empty()) {
        int i = pos.back();
        int a = get(s.substr(0, i));
        sub(a, get(s.substr(i + 1, sz(s) - i - 1)));
        return a;
    }
    balance = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '(') {
            ++balance;
        } else if (s[i] == ')') {
            --balance;
        }
        if (balance == 0 && (s[i] == '*' || s[i] == '/')) {
            pos.pb(i);
        }
    }
    if (!pos.empty()) {
        int i = pos.back();
        int a = get(s.substr(0, i));
        int b = get(s.substr(i + 1, sz(s) - i - 1));
        if (s[i] == '*') {
            mul(a, b);
        } else {
            a /= b;
        }
        return a;
    }
    assert(s[0] == 'f' && s[1] == '(' && s.back() == ')');
    int x = get(s.substr(2, sz(s) - 3));
    return result[x];
}

string trans(int val) {
    if (val == 0) {
        return "0";
    }
    string ans = "";
    while (val) {
        ans += char(val % 10 + '0');
        val /= 10;
    }
    reverse(all(ans));
    return ans;
}

int solve(int n) {
    string x = trans(n);
    bool started = false;
    int curr = 0;
    while (!started) {
        if (program[curr] == '{') {
            started = true;
            ++curr;
            break;
        }
        ++curr;
    }
    while (true) {
        if (program[curr] == 'r') {
            string ans = "";
            curr += 6;
            while (program[curr] != ';') {
                if (program[curr] == 'n') {
                    ans += x;
                } else {
                    ans += program[curr];
                }
                ++curr;
            }
            result[n] = get(ans);
            return result[n];
        }
        assert(program[curr] == 'i');
        int balance = 1;
        curr += 3;
        string lf = "", rg = "";
        char sgn = '?';
        while (balance != 0) {
            if (program[curr] == '<' || program[curr] == '>' || program[curr] == '=') {
                sgn = program[curr];
                ++curr;
                continue;
            }
            if (program[curr] == '(') {
                ++balance;
            } else if (program[curr] == ')') {
                --balance;
            }
            if (balance == 0) {
                break;
            }
            if (sgn == '?') {
                if (program[curr] == 'n') {
                    lf += x;
                } else {
                    lf += program[curr];
                }
            } else {
                if (program[curr] == 'n') {
                    rg += x;
                } else {
                    rg += program[curr];
                }
            }
            ++curr;
        }
        assert(program[curr] == ')');
        ++curr;
        int a = get(lf), b = get(rg);
        bool ok = false;
        if (sgn == '<' && a < b) {
            ok = true;
        } else if (sgn == '=' && a == b) {
            ok = true;
        } else if (sgn == '>' && a > b) {
            ok = true;
        }
        if (!ok) {
            while (program[curr] != ';') {
                ++curr;
            }
            ++curr;
            continue;
        }
        assert(program[curr] == 'r');
        string ans = "";
        curr += 6;
        while (program[curr] != ';') {
            if (program[curr] == 'n') {
                ans += x;
            } else {
                ans += program[curr];
            }
            ++curr;
        }
        result[n] = get(ans);
        return result[n];
    }
    assert(false);
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("correct.txt");

    int res;
    cin >> res;

    char c;
    while (cin >> c) {
        program.pb(c);
    }

    for (int n = 0; n < nmax; ++n) {
        result[n] = solve(n);
    }

    /*for (int n = 0; n < 101; ++n) {
        cout << result[n] << "\n";
    }*/

    //cout << result[29] << "\n";

    int ans = -1;
    for (int n = 0; n < nmax; ++n) {
        if (result[n] == res) {
            ans = n;
        }
    }

    cout << ans << "\n";

}