#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length()%2==0){
        cout << s.length()/2; 
        return 0;
    }
    int c1 = 0;
    for (char c:s) c1 += (c=='1');
    if (c1 <= 1) cout << s.length()/2;
    else cout << s.length()/2+1;
    return 0;
}