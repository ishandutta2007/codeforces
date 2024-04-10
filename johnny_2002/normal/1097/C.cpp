#include <bits/stdc++.h>

using namespace std;

map<int, int> ma;
vector<char> st;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        st.clear();
        for(auto ch : s) {
            if (ch == ')' && !st.empty() && st.back() == '(') 
                st.pop_back();
            else st.push_back(ch);
        }
        if (st.empty()) ma[0]++;
        else if (count(st.begin(), st.end(), st[0]) == st.size()) {
            ma[((st[0] == ')') ? 1 : -1) * int(st.size())]++;
        }
    }
    int ans = ma[0] / 2;
    for(auto i : ma) if (i.first < 0) 
        ans += min(i.second, ma[-i.first]);
    cout << ans;
}