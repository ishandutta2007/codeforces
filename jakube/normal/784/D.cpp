#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> inverse = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5, 8};

    string s;
    cin >> s;
    
    vector<int> cor, inv;
    for (char c : s) {
        cor.push_back(c - '0');
        inv.push_back(inverse[c - '0']);
    }
    reverse(inv.begin(), inv.end());
    
    cout << (inv == cor ? "Yes" : "No") << endl;

}