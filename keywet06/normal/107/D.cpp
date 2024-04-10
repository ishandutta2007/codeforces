#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int Z = 123;
const int P = 12345;

struct Matrix {
    friend Matrix operator*(Matrix A, Matrix B);

    int data[Z][Z];

    Matrix(int scalar = 0) {
        memset(data, 0, sizeof(data));
        for (int i = 0; i < Z; ++i) data[i][i] = scalar;
    }

    Matrix pow(int64 index) {
        Matrix P = *this;
        Matrix E(1);
        for (; index; index >>= 1) {
            if (index & 1) E = E * P;
            P = P * P;
        }
        return E;
    }

    int *operator[](const int x) { return data[x]; }
};

Matrix operator*(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < Z; ++i) {
        for (int k = 0; k < Z; ++k) {
            for (int j = 0; j < Z; ++j) {
                C[i][j] += (A[i][k] * B[k][j]) % P;
            }
        }
    }
    for (int i = 0; i < Z; ++i) {
        for (int j = 0; j < Z; ++j) C[i][j] %= P;
    }
    return C;
}

set<char> permitted;
vector<pair<char, int> > rules;
vector<vector<int> > states;

vector<int> curState;
void genStates(int curRule) {
    if (curRule == rules.size()) {
        states.push_back(curState);
        return;
    }

    for (int i = 0; i < rules[curRule].second; ++i) {
        curState.push_back(i);
        genStates(curRule + 1);
        curState.pop_back();
    }
}

bool isGood(vector<int> state) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (permitted.find(c) != permitted.end()) continue;
        bool ruleFound = false;
        bool satisfyAny = false;
        for (int i = 0; i < rules.size(); ++i) {
            if (rules[i].first == c) {
                ruleFound = true;
                satisfyAny |= state[i] == 0;
            }
        }
        if (ruleFound && !satisfyAny) return false;
    }
    return true;
}

int main() {
    int64 n;
    int c;
    cin >> n >> c;
    for (int i = 0; i < c; ++i) {
        char c;
        int m;
        cin >> c >> m;
        if (m > 1) {
            rules.push_back(make_pair(c, m));
        } else {
            permitted.insert(c);
        }
    }
    genStates(0);
    Matrix A;
    for (int i = 0; i < states.size(); ++i) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (permitted.find(c) != permitted.end()) {
                ++A[i][i];
            } else {
                bool ruleFound = false;
                vector<int> nextState = states[i];
                for (int j = 0; j < rules.size(); ++j) {
                    if (rules[j].first == c) {
                        nextState[j] = (nextState[j] + 1) % rules[j].second;
                        ruleFound = true;
                    }
                }
                if (ruleFound) {
                    int j = find(states.begin(), states.end(), nextState) -
                            states.begin();
                    ++A[i][j];
                }
            }
        }
    }
    Matrix B = A.pow(n);
    int64 ans = 0;
    for (int i = 0; i < states.size(); ++i) {
        if (isGood(states[i])) ans = (ans + B[0][i]) % P;
    }
    cout << ans << '\n';
    return 0;
}