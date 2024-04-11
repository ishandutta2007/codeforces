#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string s, t;
    cin >> s >> t;
    if(s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }
    string vowel = "aiueo";
    for(int i = 0; i < s.size(); i++) {
        bool check[2] = {false, false};
        for(int j = 0; j < 5; j++) {
            if(s[i] == vowel[j]) check[0] = true;
            if(t[i] == vowel[j]) check[1] = true;
        }
        if(check[0] != check[1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}