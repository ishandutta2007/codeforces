#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string inp[n];
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    int duped[n];
    for (int i = 0; i < n; i++) {
        duped[i] = -1;
    }

    vector<int> prnt;

    int numdupes = 0;
    for (int i = 0; i < n; i++) {
        reverse(inp[i].begin(), inp[i].end());
        if (duped[i] != -1) continue;
        for (int j = i+1; j < n; j++) {
            if (duped[j] != -1) continue;
            
            if (inp[i] == inp[j]) {
                numdupes++;
                duped[i] = j;
                duped[j] = i;
                prnt.push_back(i);
                break;
            }

        }
        reverse(inp[i].begin(), inp[i].end());
    }

    bool pally = false;
    int pallindex = -1;
    for (int i = 0; i < n; i++) {
        if (duped[i] != -1) continue;

        string cpy;
        for (int j = 0; j < m; j++) {
            cpy.push_back(inp[i][j]);
        }
        reverse(cpy.begin(), cpy.end());
        if (cpy == inp[i]) {
            pally = true;
            pallindex = i;
        }
    }
    int yeet = 2*numdupes*m;
    if (pally) {
        yeet += m;
    }

    cout << yeet << endl;

    for (int aaa : prnt) {
        cout << inp[aaa];
    }

    if (pally) {
        cout << inp[pallindex];
    }


    for (int i = prnt.size()-1; i >= 0; i--) {
        reverse(inp[prnt[i]].begin(), inp[prnt[i]].end());
        cout << inp[prnt[i]];
    }
    cout << endl;


}