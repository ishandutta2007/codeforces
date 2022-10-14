#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int mxN = 3e5;
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        stack<char> st;
        for(char c: s) {
            st.push(c);
            while(st.size()>1) {
                char last = st.top();
                st.pop();
                char before = st.top();
                if((before == 'B' and last == 'B') or (before == 'A' and last == 'B')) {
                    st.pop();
                } else {
                    st.push(last);
                    break;
                }
            }
        }
        cout << st.size() << endl;

    }
}