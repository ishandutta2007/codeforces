#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int d = 0, r = 0;
    vector<bool> order;
    for (char c : s) {
        if (c == 'D') {
            d++;
        } else {
            r++;
        }
        order.push_back(c == 'D');
    }

    int removeD = 0, removeR = 0;
    bool changed = true;
    while (order.size() && changed) {
        changed = false;
        vector<bool> new_order;
        for (int i = 0; i < order.size(); i++) {
            if (order[i]) {
                // democrat
                if (removeD > 0) {
                    removeD--;
                    changed = true;
                }
                else {
                    new_order.push_back(true);
                    removeR++;
                }
            }
            else 
            {
                if (removeR > 0) 
                {
                    removeR--;
                    changed = true;
                }
                else {
                    new_order.push_back(false);
                    removeD++;
                }
            }
        }
        order = new_order;
    }

    if (order.front()) cout << "D" << endl;
    else cout << "R" << endl;

    

    return 0;
}