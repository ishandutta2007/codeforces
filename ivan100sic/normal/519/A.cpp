#include <bits/stdc++.h>
using namespace std;

int main() {
        int a=0, b=0;
        map<char, int> val;
        val['q'] = 9;
        val['r'] = 5;
        val['b'] = 3; 
        val['n'] = 3;
        val['p'] = 1;
        for (int i=0; i<8; i++) {
                string s;
                cin >> s;
                for (char x : s) {
                        if (islower(x)) {
                                a += val[x];
                        } else if (isupper(x)) {
                                b += val[x+32];
                        }
                }
        }
        if (a > b) {
                cout << "Black";
        } else if (a < b) {
                cout << "White";
        } else {
                cout << "Draw";
        }
        cout << "\n";
}