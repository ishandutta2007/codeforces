#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p[n], x, m = 0;
    p[0] = 0;
    for (int i = 1; i < n; i++){
        cin >> x;
        p[i] = p[i-1] + x;
        m = min(p[i], m);
    }
    set<int> st;
    for (int i = 0; i < n; i++){
        p[i] -= m-1;
        st.insert(p[i]);
    }
    for (int i = 1; i <= n; i++){
        if (!st.count(i)) return cout << -1, 0;
    }
    for (auto s:p) cout << s << ' ';
}