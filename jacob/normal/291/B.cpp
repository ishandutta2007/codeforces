#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

int main(void) {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    string line;
    getline(cin, line);
    bool isOpen = false;
    for (size_t i = 0; i < line.length(); ++i) {
        while (i < line.length() && isspace(line[i]))
            ++i;
        if (i == line.length())
            break;
        cout << "<";
        if (line[i] == '"') {
            ++i;
            while (line[i] != '"') {
                cout << line[i];
                ++i;
            }
            ++i;
        } else {
            while (i < line.length() && !isspace(line[i])) {
                cout << line[i];
                ++i;
            }
        }
        cout << ">" << endl;
    }
    return 0;
}