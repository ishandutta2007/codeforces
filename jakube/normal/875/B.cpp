#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    set<int> s;
    stack<int> st;
    for (int i = 1; i <= n; i++)
        st.push(i);

    for (int i = 0; i < n; i++) {
        while (s.count(st.top()))
            st.pop();

        int to_pos = n - i;
        int pos = st.top();
        cout << abs(to_pos - pos) + 1 << ' ';

        s.insert(v[i]);
    }
    cout << 1 << endl;
}