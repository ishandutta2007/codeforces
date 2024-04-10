#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int out = 0;
    for (int i = 1; i < n; i++) {
        if (n%i == 0) out++;
    }
    cout << out << endl;
}