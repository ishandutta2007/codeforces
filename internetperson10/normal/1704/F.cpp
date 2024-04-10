#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool whoWins(string s, char c) {
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == c || s[i+1] == c) {
            string s2 = s;
            s2[i] = s2[i+1] = 'X';
            if(!whoWins(s2, 'R' + 'B' - c)) return true;
        }
    }
    return false;
}

int v[500001];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int rCount = 0, bCount = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') rCount++;
        else bCount++;
    }
    if(rCount != bCount) {
        if(rCount > bCount) cout << "Alice\n";
        else if(bCount > rCount) cout << "Bob\n";
        return;
    }
    vector<int> vee;
    int c = 1;
    for(int i = 0; i < n-1; i++) {
        if(s[i] != s[i+1]) {
            c++;
        }
        else if(c > 1) {
            vee.push_back(c);
            c = 1;
        }
    }
    if(c > 1) vee.push_back(c);
    int xs = 0;
    for(int g : vee) {
        if(g > 200) xs ^= v[102 + (g % 34)];
        else xs ^= v[g];
    }
    if(xs == 0) cout << "Bob\n";
    else cout << "Alice\n";
    vee.clear();
}

int main() {
    v[0] = 0;
    v[1] = 0;
    for(int i = 2; i <= 200; i++) {
        set<int> s;
        for(int j = 0; j <= i-2; j++) {
            s.insert(v[j] ^ v[i-j-2]);
        }
        for(int k = 0; k < 500; k++) {
            if(!s.count(k)) {
                v[i] = k;
                s.clear();
                break;
            }
        }
    }
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}