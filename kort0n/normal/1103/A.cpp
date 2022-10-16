#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    bool checker[2] = {true, true};
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        int check = 0;
        if(s[i] == '1') check = 1;
        if(check) {
            if(checker[check]) {
                cout << "1 3" << endl;
            } else {
                cout << "1 1" << endl;
            }
            checker[check] = !checker[check];
            continue;
        }
        if(checker[0]) {
            cout << "3 1" << endl;
        } else {
            cout << "1 1" << endl;
        }
        checker[0] = !checker[0];
    }
    return 0;
}