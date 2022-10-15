#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string s;
    cin >> s;
    int x4 = 0, x7 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '4')
            ++x4;
        if (s[i] == '7')
            ++x7;

    }
    if (x7 > x4)
        cout << 7 << endl;
    else
        if (x4 > 0)
            cout << 4 << endl;
        else
            cout << -1 << endl;
    
    return 0;
}