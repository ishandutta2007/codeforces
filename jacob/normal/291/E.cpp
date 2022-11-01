#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, string> edge;

vector< vector<edge> > edges;
int m;
vector< vector<int> > transitions;

int dfs(int p, int state) {
    int result = 0;
    for each (edge e in edges[p]) {
        int myState = state;
        for each (char ch in e.second) {
            myState = transitions[myState][ch - 'a'];
            if (myState == m) {
                ++result;
            }
        }
        result += dfs(e.first, myState);
    }
    return result;
}

int main(void) {
    int  n;
    ios::sync_with_stdio(false);
    cin >> n;
    edges.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        string str;
        cin >> p >> str;
        --p;
        edges[p].push_back(edge(i, str));
    }
    string pattern;
    cin >> pattern;
    m = (int)pattern.length();
    vector<int> pi(m + 1);
    transitions.assign(m + 1, vector<int>(26));
    pi[0] = -1;
    for (int i = 1; i <= m; ++i) {
        int p = pi[i-1];
        while (p != -1) {
            if (pattern[p] == pattern[i-1]) {
                break;
            }
            p = pi[p];
        };
        pi[i] = p + 1;
    }
    for (int i = 0; i <= m; ++i) {
        char ch = (i == m) ? 26 : (pattern[i] - 'a');
        for (int j = 0; j < 26; ++j) {
            if (j == ch) {
                transitions[i][j] = i + 1;
            } else {
                int st = pi[i];
                if (st == -1) {
                    transitions[i][j] = 0;
                } else {
                    transitions[i][j] = transitions[st][j];
                }
            }
        }
    }
    cout << dfs(0, 0) << endl;
    return 0;
}