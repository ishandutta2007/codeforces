#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> b;
        for (int i = 0; i < b.length(); i += 2) {
            a.push_back(b[i]);
        }
        a.push_back(b[b.length() - 1]);
        cout << a << "\n";
    }
}