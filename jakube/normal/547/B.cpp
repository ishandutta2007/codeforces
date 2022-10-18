#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<int> dur(n, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= v[i]) {
            st.pop();
        }
        if (!st.empty()) {
            dur[i] += i - st.top().second;
        }
        else 
            dur[i] = i + 1;
        st.push({v[i], i});
    }

    stack<pair<int, int>> st2;
    for (int i = n-1; i >= 0; i--) {
        while (!st2.empty() && st2.top().first >= v[i]) {
            st2.pop();
        }
        if (!st2.empty()) {
            dur[i] += st2.top().second - i - 1;
        }
        else dur[i] += n - i - 1;
        st2.push({v[i], i});
    }

    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&v](int a, int b){ return v[a] > v[b]; });

    vector<int> result(n);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (dur[indices[idx]] <= i) 
            idx++;
        cout << v[indices[idx]] << ' ';
    }
    cout << endl;

    return 0;
}