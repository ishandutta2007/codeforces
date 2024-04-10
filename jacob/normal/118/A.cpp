#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

const char VOWELS[] = "AOYEUIaoyeui";

int main(void) {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<char> res;
    for (int i = 0; i < n; i++) {
        if (find(VOWELS, VOWELS+12, s[i]) != VOWELS+12) continue;
        cout << "." << (char)tolower(s[i]);
    }
    cout << endl;
    return 0;
}