#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stuff[n];
    for (int i = 0; i < n; i++) {
        cin >> stuff[i];
    }

    sort(stuff, stuff+n);
    int out = 0;
    for (int i = 0; i < n; i++) {
        if (stuff[i] > out) {
            out++;
        }
    }
    cout << out << endl;
}