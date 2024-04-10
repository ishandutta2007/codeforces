#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n,x,y;
    cin >> n >> x >> y >> s;
    s = s.substr(n-x);
    int c = 0;
    for (int i = 0; i < x; i++){
        if(s[i] == '0' && i == x-y-1) c ++;
        if(s[i] == '1' && i != x-y-1) c ++;
    }
    cout << c;
    return 0;
}