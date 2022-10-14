#include<bits/stdc++.h>

using namespace std;

int n;
set <int> st;

void precompute () {
    int val = 1, sign = -1, pot = 1;
    for (int i = 0; i < 21; i++) {
        st.insert(val + pot);
        st.insert(val + pot + sign);
        val = val * 2 + sign;
        sign = -sign;
        pot = pot * 2 + 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> n;
    if (st.find(n) != st.end()) cout << 1; else cout << 0;
    return 0;
}