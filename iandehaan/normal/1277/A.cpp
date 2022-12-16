#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tempn = n/10;
        int out = 0;
        int numdigits = 0;
        while (tempn) {
            tempn /= 10;
            out += 9;
            numdigits++;
        }
        
        for (int i = 1; i <= 9; i++) {
            int64_t temp = i;
            for (int j = 0; j < numdigits; j++) {
                temp *= 10;
                temp += i;
            }
            //cout << temp << endl;
            if (n >= temp) {
                //cout << temp << endl;
                out++;
            }
        }
        cout << out << endl;
    }
}