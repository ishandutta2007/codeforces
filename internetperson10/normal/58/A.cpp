#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, hello = "hello";
    cin >> s;
    int b=0;
    for(int a=0; a<s.size() && b<5; a++) {
        if(s.at(a)==hello.at(b)) b++;
    }
    if(b==5) cout << "YES";
    else cout << "NO";
}