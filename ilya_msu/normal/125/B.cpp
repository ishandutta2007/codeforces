#include<iostream>
#include<vector>
#include<string>
#include<stack>

using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;


int main() {
    stack<char> st;
    char c;
    while (cin >> c) {
        //cin >> c;
        cin >> c;
        if (c == '/') {
            st.pop();
           
            cin >> c;
            
            for (int i = 0; i < st.size(); ++i)
                cout << "  ";
            cout << "</" << c << ">" << endl;
        }
        else {
             for (int i = 0; i < st.size(); ++i)
                cout << "  ";            
            st.push(c);
            cout << "<" << c << ">" << endl;
        }
        cin >> c;
    }
    
    return 0;
}