#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int k;
        cin >> k;
        string ting;
        cin >> ting;
        int lastA = -1;
        int out = 0;
        for (int i = 0; i < k; i++) {
            if (ting[i] == 'A') {
                lastA = i;
            } else if (lastA != -1) {
                int current = i - lastA;
                out = max(out, current);
            }
        }
        cout << out << endl;
    }
}