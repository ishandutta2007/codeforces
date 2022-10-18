#include <bits/stdc++.h>
using namespace std;

struct Op {
    bool is_constant;
    string value;

    int var1;
    bool op_xor = false;
    bool op_and = false;
    bool op_or = false;
    int var2;
};

vector<Op> operations;
vector<int> values;

int compute(int bit, int peter, int op_idx) {
    Op& op = operations[op_idx];
    if (op.is_constant)
        return values[op_idx] = op.value[bit] == '0' ? 0 : 1;

    int v1 = op.var1 == -1 ? peter : values[op.var1];
    int v2 = op.var2 == -1 ? peter : values[op.var2];

    if (op.op_xor)
        return values[op_idx] = v1 ^ v2;
    if (op.op_and)
        return values[op_idx] = v1 & v2;
    if (op.op_or)
        return values[op_idx] = v1 | v2;

    return 999;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    map<string, int> variables;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string var, sign;
        cin >> var >> sign;
        variables[var] = cnt;
        cnt++;

        string t;
        cin >> t;
        if (t[0] == '0' || t[0] == '1') {
            Op o;
            o.is_constant = true;
            o.value = t;
            operations.push_back(o);
            continue;
        }

        string oo, r;
        cin >> oo >> r;
        Op o;
        o.is_constant = false;
        if (t == "?")
            o.var1 = -1;
        else 
            o.var1 = variables[t];

        if (oo == "XOR")
            o.op_xor = true;
        if (oo == "AND")
            o.op_and = true;
        if (oo == "OR")
            o.op_or = true;

        if (r == "?")
            o.var2 = -1;
        else
            o.var2 = variables[r];
        operations.push_back(o);
    }


    values.resize(n);
    vector<char> mi, ma;
    for (int i = 0; i < m; i++) {
        int sums[2] = {0};
        for (int peter = 0; peter < 2; peter++) {
            for (int j = 0; j < n; j++) {
                sums[peter] += compute(i, peter, j);
            }
        }

        if (sums[0] <= sums[1]) {
            mi.push_back('0');
        } else {
            mi.push_back('1');
        }

        if (sums[0] >= sums[1]) {
            ma.push_back('0');
        } else {
            ma.push_back('1');
        }
    }

    for (char c : mi)
        cout << c;
    cout << endl;
    for (char c : ma)
        cout << c;
    cout << endl;
}