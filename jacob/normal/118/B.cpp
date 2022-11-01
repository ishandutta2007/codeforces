#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

const char VOWELS[] = "AOYEUIaoyeui";

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < 2*n + 1; i++) {
        int c = min(i+1, 2*n + 1 - i);
        int o = n - c + 1;
        for (int j = 0; j < o; j++)
           cout << "  ";
        for (int j = 1; j <= c; j++) {
            if (j != 1) cout << " ";
            cout << j-1;
        }
        for (int j = c - 1; j > 0; j--)
            cout << " " << j-1;
        cout << endl;
    }
    return 0;
}