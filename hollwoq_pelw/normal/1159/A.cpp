#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int c = 0, mn = 0;
    for (char t:s){
        if (t == '-') c--;
        if (t == '+') c++;
        if (mn > c) mn = c;
    }
    cout << c-mn;
    return 0;
}