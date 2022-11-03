#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    set<string> st;
    cin >> s;
    st.insert(s);
    for(int i = 1; i < s.length(); ++i){
        s += s[0];
        s = s.substr(1, s.length() - 1);
        st.insert(s);
    }
    cout << st.size() << endl;
}