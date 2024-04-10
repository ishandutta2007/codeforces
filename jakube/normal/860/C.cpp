#include <bits/stdc++.h>

using namespace std;

struct S
{
    string name;
    int type;
};

int main() {
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    vector<S> v(n);
    int examples = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].type;
        examples += v[i].type;
    }

    vector<bool> correct(n + 1, false);
    vector<bool> blocked(n + 1, false);

    vector<S> examples_blocking, tests_blocking, others;

    vector<bool> existing(1000000, false);

    for (int i = 0; i < n; i++) {
        string s = v[i].name;
        int type = v[i].type;

        int x;
        stringstream ss(s);
        ss >> x;
        bool num = s == to_string(x) && s[0] != 0 && x <= n;
        if (num) {
            existing[num] = true;
            if (type == 1 && x <= examples) {
                // do nothing
                correct[x] = true;
            } else if (type == 1) {
                examples_blocking.push_back(v[i]);
                blocked[x] = true;
            } else if (type == 0 && x > examples && x <= n) {
                // do nothing
                correct[x] = true;
            } else if (type == 0) {
                tests_blocking.push_back(v[i]);
                blocked[x] = true;
            }
        } else {
            others.push_back(v[i]);
        }
    }

    int tmp = 999999;
    while (existing[tmp])
        tmp--;

    int idx_examples = 1, idx_tests = examples + 1;
    vector<int> not_blocked_examples, not_blocked_tests;
    for (int i = 1; i <= examples; i++) {
        if (!blocked[i] && !correct[i])
            not_blocked_examples.push_back(i);
    }
    for (int i = examples + 1; i <= n; i++) {
        if (!blocked[i] && !correct[i])
            not_blocked_tests.push_back(i);
    }

    vector<pair<string, string>> moves;
    int result = 0;

    while (examples_blocking.size() || tests_blocking.size()) {
        while ((examples_blocking.size() && not_blocked_examples.size()) || (tests_blocking.size() && not_blocked_tests.size())) {
            while (examples_blocking.size() && not_blocked_examples.size()) {
                auto p = examples_blocking.back();
                examples_blocking.pop_back();
                int pos = not_blocked_examples.back();
                not_blocked_examples.pop_back();
                result++;
                moves.push_back({p.name, to_string(pos)});
                stringstream ss(p.name);
                int x;
                ss >> x;
                not_blocked_tests.push_back(x);
            }

            while (tests_blocking.size() && not_blocked_tests.size()) {
                auto p = tests_blocking.back();
                tests_blocking.pop_back();
                int pos = not_blocked_tests.back();
                not_blocked_tests.pop_back();
                result++;
                moves.push_back({p.name, to_string(pos)});
                stringstream ss(p.name);
                int x;
                ss >> x;
                not_blocked_examples.push_back(x);
            }
        }

        if (examples_blocking.size() || tests_blocking.size()) {
            auto p = examples_blocking.back();
            examples_blocking.pop_back();
            moves.push_back({p.name, to_string(tmp)});
            stringstream ss(p.name);
            int x;
            ss >> x;
            not_blocked_tests.push_back(x);
            S s;
            s.name = to_string(tmp);
            s.type = 1;
            others.push_back(s);
        }
    }

    for (auto &s : others) {
        if (s.type == 1) {
            int pos = not_blocked_examples.back();
            not_blocked_examples.pop_back();
            moves.push_back({s.name, to_string(pos)});
        }
        else {
            int pos = not_blocked_tests.back();
            not_blocked_tests.pop_back();
            moves.push_back({s.name, to_string(pos)});
        }
    }
   
    cout << moves.size() << '\n';
    for (auto &m : moves) {
        cout << "move " << m.first << " " << m.second << '\n';
    }
}