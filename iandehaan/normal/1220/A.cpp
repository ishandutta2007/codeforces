#include <iostream>
using namespace std;

int main() {
    int n;
    int o = 0;
    int z = 0;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'z') z++;
        else if (c == 'n') o++;
    }
    while (o--) cout << "1 ";
    while (z--) cout << "0 ";
    cout << endl;
}