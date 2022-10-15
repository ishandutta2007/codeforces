#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>

using namespace std;

int main() {
    char c;
    stack<char> st;
    while (cin >> c) {
        if (st.empty())
            st.push(c);
        else {
            char c1 = st.top();
            if (c1 == c)
                st.pop();
            else
                st.push(c);
        }
    }
    vector<char> data;
    while (!st.empty()) {
        data.push_back(st.top());
        st.pop();
    }
    for (int i = data.size() - 1; i > -1; --i)
        cout << data[i];
    cout << endl;
    return 0;
}