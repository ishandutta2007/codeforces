#include <iostream>
using namespace std;

int out, n;
int denoms[] = {1, 5, 10, 20, 100};

int main() {
    cin >> n;
    for (int i = 4; i >= 0; i--) {
        while (n >= denoms[i]) {
            out++;
            n -= denoms[i];
        }
    }
    cout << out << endl;
}