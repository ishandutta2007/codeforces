#include <bits/stdc++.h>
using namespace std;


vector<string> guess(string num, vector<string> left) {
    // cout << left.size() << endl;
    cout << num << endl;
    int a, b;
    cin >> a >> b;
    if (a == 4 && b == 0) {
        return {};
    }
    
    bool used[10] = {false};
    for (char c : num) {
        used[c - '0'] = true;
    }

    vector<string> out;
    for (string &s : left) {
        int A = 0;
        int B = 0;
        for (int i = 0; i < 4; i++) {
            if (used[s[i] - '0'])
                B++;
            if (s[i] == num[i])
                A++;
        }
        B -= A;
        if (A == a && B == b) {
            out.push_back(s);
        }
    }

    return out;
}

string choose_best(vector<string> left, vector<string> &all) {
    string best;
    int worst_result = 1000000;

    for (string num : all) {
        bool used[10] = {false};
        for (char c : num) {
            used[c - '0'] = true;
        }

        vector<vector<int>> cnt(5, vector<int>(5, 0));
        for (string &s : left) {
            int A = 0;
            int B = 0;
            for (int i = 0; i < 4; i++) {
                if (used[s[i] - '0'])
                    B++;
                if (s[i] == num[i])
                    A++;
            }
            B -= A;
            cnt[A][B]++;
        }
        
        int worst = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                worst = max(worst, cnt[i][j]);
            }
        }

        if (worst < worst_result) {
            worst_result = worst;
            best = num;
        }
        else if (worst == worst_result && count(left.begin(), left.end(), num)) {
            best = num;
        }
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<string> left;
    vector<string> all;
    for (int i = 0; i < 10000; i++) {
        string s = "";
        s += ((i / 1000) % 10) + '0';
        s += ((i / 100) % 10) + '0';
        s += ((i / 10) % 10) + '0';
        s += ((i) % 10) + '0';
        if (s[0] != s[1] && s[0] != s[2] && s[0] != s[3] && s[1] != s[2] && s[1] != s[3] && s[2] != s[3])
            left.push_back(s);
        all.push_back(s);
    }
    
    left = guess("0011", left);

    while (left.size() > 1) {
        string s = choose_best(left, all);
        left = guess(s, left);
    }

    if (left.size() == 1) {
        cout << left.front() << endl;
    }

    return 0;
}