#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int numa = 0;
    for (char c : s) {
        if (c == 'a') numa++;
    }
    cout << min(2*numa-1, (int)s.size()) << endl;
}