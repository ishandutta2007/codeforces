#include <bits/stdc++.h>
using namespace std;
int main(){
    int a = 0;
    string s;
    cin >> s;
    stack<char> st;
    for (auto c: s){
        if (st.size()>0&&st.top()==c) {a++; st.pop();}
        else st.push(c);
    }
    if (a%2) cout << "Yes";
    else cout << "No";
    return 0;
}