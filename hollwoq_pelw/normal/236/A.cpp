#include <bits/stdc++.h>
#include <set>
using namespace std;
int main(){
    string s;
    set<char> a;
    cin >> s;
    for (char c:s) a.insert(c);
    if ( a.size() % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}