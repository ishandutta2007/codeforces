#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int mi, ch;
    cin >> c;
    ch = c - '0';
    cin >> c;
    ch = ch * 10 + c - '0';
    cin >> c;
    cin >> c;
    mi = c - '0';
    cin >> c;
    mi = mi * 10 + c - '0';
    int i = 0;
    bool found = ((ch/10 == mi % 10) && (ch % 10 == mi /10));
    while (found == false) {
        mi++;
        if (mi == 60) {
            ch++;
            mi = 0;
        }
        if (ch == 24)
            ch = 0;
        found = ((ch/10 == mi % 10) && (ch % 10 == mi /10));
        i++;
    }
    cout << i;
}