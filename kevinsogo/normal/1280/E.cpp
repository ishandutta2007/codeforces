#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

class Circuit {
public:
    ll w = -1;
    ll width() {
        if (w == -1) compute_width();
        return w;
    }
    virtual void compute_width() {}
    virtual void assign(ll value) {}
    virtual ostream& write_to(ostream& os) const { return os; }
    void assign_minimal(ll value) { assign(value * width()); }
    friend ostream& operator<<(ostream& os, const Circuit& circuit);
};

ostream& operator<<(ostream& os, const Circuit& circuit) {
    return circuit.write_to(os);
}

class Resistor: public Circuit {
public:
    ll value = -1;
    Resistor() {}
    void compute_width() override {
        w = 1;
    }
    void assign(ll value) override {
        this->value = value;
    }
    ostream& write_to(ostream& os) const override {
        return os << ' ' << value;
    }
};

class Join: public Circuit {
public:
    char typ;
    vector<Circuit*> children;
    Join() {}
    void compute_width() override {
        w = typ == 'S' ? INF : 0;
        for (auto child: children) {
            ll ww = child->width();
            w = typ == 'S' ? min(w, ww) : w + ww;
        }
    }
    void assign(ll value) override {
        for (auto child: children) {
            if (typ == 'S') {
                if (child->width() == width()) {
                    child->assign(value);
                    value = 0;
                } else {
                    child->assign(0);
                }
            } else {
                child->assign(value);
            }
        }
    }
    ostream& write_to(ostream& os) const override {
        for (auto child: children) os << *child;
        return os;
    }
};

class CircuitParser {
    const string& s;
    int i = 0;
    CircuitParser(const string& s): s(s) {}
    Circuit *parse() {
        if (s[i++] == '(') {
            Join *j = new Join();
            while (true) {
                j->children.push_back(parse());
                if (s[i++] == ')') break;
                j->typ = s[i++];
                i++;
            }
            return j;
        } else {
            return new Resistor();
        }
    }
public:
    static Circuit *parse(const string& s) {
        return CircuitParser(s).parse();
    }
};

void solve(ll a, const string& s) {
    Circuit *c = CircuitParser::parse(s);
    c->assign_minimal(a);
    cout << "REVOLTING" << *c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    for (cin >> z; z--;) {
        ll a;
        string s;
        cin >> a;
        getline(cin, s);
        assert(s[0] == ' ');
        solve(a, s.substr(1));
    }
}