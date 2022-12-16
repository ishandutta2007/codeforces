#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string inp;
        cin >> inp;

        int start1 = 1;

        // shortest possible
        for (char c : inp) {
            if (c == '>') {
                start1++;
            }
        }
        cout << start1 << ' ';


        int bigboy1 = n;
        start1--;
        for (int i = 0; i < inp.size(); i++) {
            if (inp[i] == '>') {
                cout << start1 << ' ';
                start1--;
                
            } else {
                //cout << "bigboy1: " << bigboy1 << endl;
                int finito = bigboy1;
                int starti = i;
                i++;
                while (i < n-1 && inp[i] == '<') {
                    bigboy1--;
                    i++;
                }
                finito = bigboy1;
                i = starti;
                while (i < n-1 && inp[i] == '<') {
                    cout << bigboy1 << ' ';
                    bigboy1++;
                    i++;
                }
                i--;
                bigboy1 = finito-1;
            }
        }
        cout << endl;


        int ind = 0;
        int used = 0;
        while (ind < n-1) {
            int amt = 0;
            while (ind < n-1 && inp[ind] == '>') {
                amt++;
                ind++;
            }
            ind++;

            int prnt = used + amt+1;
            while (prnt > used) {
                cout << prnt << ' ';
                prnt--;
            }
            used += amt+1;
        }
        if (used <= n-1) {
            cout << used+1;
        }
        cout << endl;
    }
}