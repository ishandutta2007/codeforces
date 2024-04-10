#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> order(n);

    int cur_order = 0;
    int sz = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '[')
            order[i] = cur_order++;
        else
            order[i] = --cur_order;

        if (i && s[i-1] == '[' && s[i] == ']')
            sz += 3;
    }

    int m = *max_element(order.begin(), order.end());
    int height = 2*m + 3;
    vector<string> res;

    //create empty space
    for (int i = 0; i < sz; i++) {
        string t;
        for (int j = 0; j < height; j++) t += ' ';
        res.push_back(t);
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int o = order[i];

        res[idx][o] = '+';
        for (int j = o + 1; j < height - o - 1; j++) res[idx][j] = '|';
        res[idx][height - o - 1] = '+';

        if (c == '[') {
            res[idx+1][o] = '-';
            res[idx+1][height - o - 1] = '-';
        } else {
            res[idx-1][o] = '-';
            res[idx-1][height - o - 1] = '-';
        }

        idx++;

        if (i + 1 < n && c == '[' && s[i+1] == ']')
            idx += 3;
    }


    // output
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < res.size(); j++)
            cout << res[j][i];
        cout << '\n';
    }
}