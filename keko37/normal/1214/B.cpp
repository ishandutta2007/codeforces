#include<bits/stdc++.h>

using namespace std;

int b, g, n;
string s;
set <string> st;

int main () {
    cin >> b >> g >> n;
    for (int i=0; i<b; i++) s += 'B';
    for (int i=0; i<g; i++) s += 'G';
    for (int i=0; i < b + g; i++) {
        if (s.substr(i, n).size() == n) st.insert(s.substr(i, n));
    }
    cout << st.size();
    return 0;
}