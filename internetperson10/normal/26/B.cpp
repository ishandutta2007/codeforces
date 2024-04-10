#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int main() {
    char toppity;
    string brackets;
    cin >> brackets;
    int a=0, st=0;
    while(a!=brackets.size()) {
        if(s.size()) toppity = s.top();
        else toppity='x';
        s.push(brackets.at(a));
        if(s.top()==')') {
            if(toppity=='(') {
                s.pop();
                s.pop();
                st+=2;
            }
            else s.pop();
        }
        a++;
    }
    cout << st;
}