#include<bits/stdc++.h>
using namespace std;

main() {
    string s;
    cin >> s;
    int x = s.back() - '0';
    cout << x % 2;
    return 0;
}