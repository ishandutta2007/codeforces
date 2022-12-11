#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct operation
{
    string l, r;
    char op;
};

vector<operation> operations;

void f1(const vector<string>& v, const vector<char>& op)///deals withs a*b/c/d*x/(sum+1)
{
    int n = sz(v);
    for (int i = 0; i < n - 1; ++i) {
        operations.pb({v[0], v[i + 1], op[i]});
    }
}

void f3(const string& s);

void f2(const vector<string>& v, const vector<char>& op)///deals with +/-*
{
    vector<string> newV;
    vector<char> newOp;
    vector<string> currV;
    vector<char> currOp;
    string curr = v[0];
    currV.pb(v[0]);
    int n = sz(v);
    /*for (int i = 0; i < n; ++i) {
        f3(v[i]);
    }*/
    for (int i = 0; i < n - 1; ++i) {
        if (op[i] == '*' || op[i] == '/') {
            curr += op[i];
            curr += v[i + 1];
            currV.pb(v[i + 1]);
            currOp.pb(op[i]);
        } else {
            newV.pb(curr);
            curr = v[i + 1];
            newOp.pb(op[i]);
            if (!currOp.empty()) {
                f1(currV, currOp);
            }
            currV = {v[i + 1]};
            currOp.clear();
        }
    }
    newV.pb(curr);
    if (!currOp.empty()) {
        f1(currV, currOp);
    }
    for (int i = 0; i < sz(newV) - 1; ++i) {
        operations.pb({newV[0], newV[i + 1], newOp[i]});
    }
}

set<string> toCheck;
map<string, string> m;
set<string> checked;

void f3(const string& s)
{
    checked.insert(s);
    int n = sz(s);
    if (m.count(s)) {
        toCheck.insert(m[s]);
        return;
    }
    int balance = 0;
    bool inPar = true;
    forn(i, n) {
        if (s[i] == '(') {
            ++balance;
        }
        if (s[i] == ')') {
            --balance;
        }
        if ((i != n - 1 && !balance) || sz(s) == 1) {
            inPar = false;
            break;
        }
    }
    if (inPar) {
        string t = "";
        for (int i = 1; i < n - 1; ++i) {
            t += s[i];
        }
        f3(t);
        return;
    }
    bool ops = false;
    forn(i, n) {
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            ops = true;
            break;
        }
    }
    if (!ops) {
        return;
    }
    vector<string> v;
    v.pb("");
    vector<char> op;
    balance = 0;
    forn(i, n) {
        if (s[i] == '(') {
            ++balance;
        }
        if (s[i] == ')') {
            --balance;
        }
        if (balance || s[i] == ')') {
            v.back() += s[i];
            continue;
        }
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            op.pb(s[i]);
            v.pb("");
            continue;
        } else {
            v.back() += s[i];
        }
    }
    f2(v, op);
}

string deleteSpaces(const string& s)
{
    string ans = "";
    int n = sz(s);
    forn(i, n) {
        if (s[i] != ' ') {
            ans += s[i];
        }
    }
    return ans;
}

set<char> freeOp(const string& s)
{
    string t = m[s];
    set<char> ans;
    int balance = 0;
    int n = sz(t);
    forn(i, n) {
        if (t[i] == '(') {
            ++balance;
            continue;
        }
        if (t[i] == ')') {
            --balance;
            continue;
        }
        if (!balance && (t[i] == '-' || t[i] == '+' || t[i] == '*' || t[i] == '/')) {
            ans.insert(t[i]);
        }
    }
    return ans;
}

bool check(const operation& o)
{
    if (m.count(o.l)) {
        toCheck.insert(m[o.l]);
    } else {
        toCheck.insert(o.l);
    }
    if (m.count(o.r)) {
        toCheck.insert(m[o.r]);
    } else {
        toCheck.insert(o.r);
    }
    if (o.op == '+') {
        return true;
    }
    if (o.op == '-') {
        if (!m.count(o.r)) {
            return true;
        }
        set<char> sr = freeOp(o.r);
        if (sr.count('+') || sr.count('-')) {
            return false;
        }
        return true;
    }
    if (o.op == '*') {
        if (m.count(o.r)) {
            set<char> sr = freeOp(o.r);
            if (sr.count('+') || sr.count('-')) {
                return false;
            }
        }
        if (m.count(o.l)) {
            set<char> sl = freeOp(o.l);
            if (sl.count('+') || sl.count('-')) {
                return false;
            }
        }
        return true;
    }
    if (o.op == '/') {
        if (m.count(o.r)) {
            set<char> sr = freeOp(o.r);
            if (!sr.empty()) {
                return false;
            }
        }
        if (m.count(o.l)) {
            set<char> sl = freeOp(o.l);
            if (sl.count('+') || sl.count('-')) {
                return false;
            }
        }
        return true;
    }
}

int main()
{

    int n;
    cin >> n;

    if (!n) {
        cout << "OK\n";
        return 0;
    }
    forn(i, n) {
        string def;
        cin >> def;
        if (def != "#define") {
            cin >> def;
        }
        string name;
        cin >> name;
        string val;
        getline(cin, val);
        m[name] = deleteSpaces(val);
    }

    string s;
    getline(cin, s);
    s = deleteSpaces(s);
    //cout << s << "\n";

    toCheck.insert(s);

    while (!toCheck.empty()) {
        operations.clear();
        string tmp = *toCheck.begin();
        if (checked.count(tmp)) {
            toCheck.erase(tmp);
            continue;
        }
        //cout << "PROCESSING " << tmp << "\n";
        f3(tmp);
        forn(i, sz(operations)) {
            //cout << operations[i].l << " " << operations[i].op << " " << operations[i].r << "\n";
            if (!check(operations[i])) {
                cout << "Suspicious\n";
                return 0;
            }
            //cout << "checked\n";
        }
        //cout << "outed\n";
        toCheck.erase(tmp);
    }

    cout << "OK\n";

}