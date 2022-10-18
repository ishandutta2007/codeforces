#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<bool> v(n-k+1);
    for (int i = 0; i < v.size(); i++) {
        string tmp;
        cin >> tmp;
        v[i] = tmp == "YES";
    }

    if (all_of(v.begin(), v.end(), [](bool b){ return !b; })) {
        for (int i = 0; i < n; i++) {
            cout << "Na ";
        }
        cout << endl;
        return 0;
    }

    vector<string> allnames;
    for (char c = 'A'; c <= 'Z'; c++) {
        for (char d = 'a'; d <= 'z'; d++) {
            for (char e = 'a'; e <= 'z'; e++) {
                string s = "";
                s += c;
                s += d;
                s += e;
                allnames.push_back(s);
            }
        }
    }

    int idx = 0;    
    vector<string> names(n);
    for (int i = 0; i < k-1; i++) {
        names[i] = allnames[idx++];
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            names[k-1+i] = allnames[idx++];
        } else {
            names[k-1+i] = names[i];
        }
    }

    for (string s : names) 
        cout << s << " ";
    cout << endl;

    return 0;
}