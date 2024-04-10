#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    string k;
    int n, x=0;
    cin >> n;
    while(n--) {
        cin >> k;
        if(k.at(0)=='+' || k.at(2)=='+')
            x++;
        else
            x--;
    }
    cout << x;
}